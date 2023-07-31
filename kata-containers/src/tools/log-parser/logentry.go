//
// Copyright (c) 2017-2018 Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
//

package main

import (
	"fmt"
	"reflect"
	"strings"
	"time"
)

// TimeDelta is a time duration type used to record the difference between two
// timestamps.
type TimeDelta time.Duration

// NewTimeDelta create a new TimeDelta from the specified duration.
func NewTimeDelta(d time.Duration) TimeDelta {
	return TimeDelta(d)
}

// String implements the Stringer interface to avoid the "clever" default for
// time.Duration which converts the value into a human-readable format (which
// varies on the value). We just want a fixed nanosecond format.
func (t TimeDelta) String() string {
	return fmt.Sprintf("%d", t)
}

// MapSS is a hack for the xml package which is unable to marshal map types
// without help.
//
// See MapSS.MarshalXML()
type MapSS map[string]string

// Version of LogEntry contents (in semver.org format).
// XXX: Update whenever LogEntry changes!
const logEntryFormatVersion = "0.0.2"

// LogEntry is the main type used by the tool. It encapsulates a number of
// fields that all system components are expected to set, but also includes
// additional fields generated by this program.
//
// Notes:
//
// - An anonymous field is not used to distinguish between the two
//   categories of fields because that extra layer becomes visible when the
//   struct is converted to various formats (specifically CSV, text and YAML).
//
// - XXX: If you change this struct, update logEntryFormatVersion!
//
type LogEntry struct {
	// Used to store additional (non-standard) fields
	Data MapSS

	Time time.Time

	// Name of the file this entry belongs to
	Filename string

	Level string
	Msg   string

	// System component type and name that generated the log entry
	Source string
	Name   string

	// Container ID. This is set for most, but not all log records.
	//
	// Excluded log records include:
	//
	// - runtime log entries where the specified CLI command does not
	//   operate on a container (or a single container).
	//
	// - proxy log entries which contain kernel boot output from the
	//   guest.
	//
	// - early startup agent log entries.
	Container string

	// Sandbox ID. This is set for most, but not all log records.
	//
	// Excluded log records include:
	//
	// - runtime log entries where the specified CLI command does not
	//   operate on a container (or a single container).
	Sandbox string

	// Line number in Filename this entry refers to
	Line uint64

	// Log entry number (1-indexed)
	Count uint64

	// difference between this record and the previous one
	TimeDelta TimeDelta

	Pid int
}

// Fields lists the names of the fields in a LogEntry.
func (le LogEntry) Fields() []string {
	var fields []string

	v := reflect.ValueOf(le)

	for i := 0; i < v.NumField(); i++ {
		field := v.Type().Field(i).Name
		fields = append(fields, field)
	}

	return fields
}

// Check runs basic checks on the LogEntry to ensure it is valid.
func (le LogEntry) Check(ignoreMissingFields bool) error {
	if le.Filename == "" {
		return fmt.Errorf("missing filename: %+v", le)
	}

	if le.Filename != stdinFile {
		if !strings.HasPrefix(le.Filename, "/") {
			return fmt.Errorf("filename not absolute: %+v", le)
		}
	}

	if le.Line == 0 {
		return fmt.Errorf("missing line number: %+v", le)
	}

	if le.Time == (time.Time{}) {
		return fmt.Errorf("missing timestamp: %+v", le)
	}

	if !ignoreMissingFields {
		if le.Pid == 0 {
			return fmt.Errorf("missing pid: %+v", le)
		}

		if le.Level == "" {
			return fmt.Errorf("missing log level: %+v", le)
		}

		if le.Source == "" {
			return fmt.Errorf("missing component source: %+v", le)
		}

		if le.Name == "" {
			return fmt.Errorf("missing component name: %+v", le)
		}
	}

	if le.Pid < 0 {
		return fmt.Errorf("invalid pid: %+v", le)
	}

	// Note: le.Container and le.Sandbox cannot be checked since they are not
	// present in all entries.

	m := map[string]string{
		"Level":  le.Level,
		"Source": le.Source,
		"Name":   le.Name,
	}

	for k, v := range m {
		fields := strings.Fields(v)
		if len(fields) > 1 {
			return fmt.Errorf("field %q cannot be multi-word: %+v", k, le)
		}
	}

	return nil
}

// LogEntries is a type that encapsulates a list of LogEntry elements.
// Strictly, this type could refer to the slice itself. However, some
// formatting packages (such as those for XML and TOML) require that the
// object to encode is a struct - not an array slice.
type LogEntries struct {
	FormatVersion string
	Entries       []LogEntry
}

// Len is required by sort.Sort.
func (e LogEntries) Len() int {
	return len(e.Entries)
}

// Swap is required by sort.Sort
func (e LogEntries) Swap(i, j int) {
	entries := e.Entries
	entries[i], entries[j] = entries[j], entries[i]
}

// Less is required by sort.Sort. Allows time-based sorting.
func (e LogEntries) Less(i, j int) bool {
	entries := e.Entries

	return entries[i].Time.Before(entries[j].Time)
}
