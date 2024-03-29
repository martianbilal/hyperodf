/*
Cloud Hypervisor API

Local HTTP based API for managing and inspecting a cloud-hypervisor virtual machine.

API version: 0.3.0
*/

// Code generated by OpenAPI Generator (https://openapi-generator.tech); DO NOT EDIT.

package openapi

import (
	"encoding/json"
)

// MemoryZoneConfig struct for MemoryZoneConfig
type MemoryZoneConfig struct {
	Id             string  `json:"id"`
	Size           int64   `json:"size"`
	File           *string `json:"file,omitempty"`
	Mergeable      *bool   `json:"mergeable,omitempty"`
	Shared         *bool   `json:"shared,omitempty"`
	Hugepages      *bool   `json:"hugepages,omitempty"`
	HugepageSize   *int64  `json:"hugepage_size,omitempty"`
	HostNumaNode   *int32  `json:"host_numa_node,omitempty"`
	HotplugSize    *int64  `json:"hotplug_size,omitempty"`
	HotpluggedSize *int64  `json:"hotplugged_size,omitempty"`
}

// NewMemoryZoneConfig instantiates a new MemoryZoneConfig object
// This constructor will assign default values to properties that have it defined,
// and makes sure properties required by API are set, but the set of arguments
// will change when the set of required properties is changed
func NewMemoryZoneConfig(id string, size int64) *MemoryZoneConfig {
	this := MemoryZoneConfig{}
	this.Id = id
	this.Size = size
	var mergeable bool = false
	this.Mergeable = &mergeable
	var shared bool = false
	this.Shared = &shared
	var hugepages bool = false
	this.Hugepages = &hugepages
	return &this
}

// NewMemoryZoneConfigWithDefaults instantiates a new MemoryZoneConfig object
// This constructor will only assign default values to properties that have it defined,
// but it doesn't guarantee that properties required by API are set
func NewMemoryZoneConfigWithDefaults() *MemoryZoneConfig {
	this := MemoryZoneConfig{}
	var mergeable bool = false
	this.Mergeable = &mergeable
	var shared bool = false
	this.Shared = &shared
	var hugepages bool = false
	this.Hugepages = &hugepages
	return &this
}

// GetId returns the Id field value
func (o *MemoryZoneConfig) GetId() string {
	if o == nil {
		var ret string
		return ret
	}

	return o.Id
}

// GetIdOk returns a tuple with the Id field value
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetIdOk() (*string, bool) {
	if o == nil {
		return nil, false
	}
	return &o.Id, true
}

// SetId sets field value
func (o *MemoryZoneConfig) SetId(v string) {
	o.Id = v
}

// GetSize returns the Size field value
func (o *MemoryZoneConfig) GetSize() int64 {
	if o == nil {
		var ret int64
		return ret
	}

	return o.Size
}

// GetSizeOk returns a tuple with the Size field value
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetSizeOk() (*int64, bool) {
	if o == nil {
		return nil, false
	}
	return &o.Size, true
}

// SetSize sets field value
func (o *MemoryZoneConfig) SetSize(v int64) {
	o.Size = v
}

// GetFile returns the File field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetFile() string {
	if o == nil || o.File == nil {
		var ret string
		return ret
	}
	return *o.File
}

// GetFileOk returns a tuple with the File field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetFileOk() (*string, bool) {
	if o == nil || o.File == nil {
		return nil, false
	}
	return o.File, true
}

// HasFile returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasFile() bool {
	if o != nil && o.File != nil {
		return true
	}

	return false
}

// SetFile gets a reference to the given string and assigns it to the File field.
func (o *MemoryZoneConfig) SetFile(v string) {
	o.File = &v
}

// GetMergeable returns the Mergeable field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetMergeable() bool {
	if o == nil || o.Mergeable == nil {
		var ret bool
		return ret
	}
	return *o.Mergeable
}

// GetMergeableOk returns a tuple with the Mergeable field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetMergeableOk() (*bool, bool) {
	if o == nil || o.Mergeable == nil {
		return nil, false
	}
	return o.Mergeable, true
}

// HasMergeable returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasMergeable() bool {
	if o != nil && o.Mergeable != nil {
		return true
	}

	return false
}

// SetMergeable gets a reference to the given bool and assigns it to the Mergeable field.
func (o *MemoryZoneConfig) SetMergeable(v bool) {
	o.Mergeable = &v
}

// GetShared returns the Shared field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetShared() bool {
	if o == nil || o.Shared == nil {
		var ret bool
		return ret
	}
	return *o.Shared
}

// GetSharedOk returns a tuple with the Shared field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetSharedOk() (*bool, bool) {
	if o == nil || o.Shared == nil {
		return nil, false
	}
	return o.Shared, true
}

// HasShared returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasShared() bool {
	if o != nil && o.Shared != nil {
		return true
	}

	return false
}

// SetShared gets a reference to the given bool and assigns it to the Shared field.
func (o *MemoryZoneConfig) SetShared(v bool) {
	o.Shared = &v
}

// GetHugepages returns the Hugepages field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetHugepages() bool {
	if o == nil || o.Hugepages == nil {
		var ret bool
		return ret
	}
	return *o.Hugepages
}

// GetHugepagesOk returns a tuple with the Hugepages field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetHugepagesOk() (*bool, bool) {
	if o == nil || o.Hugepages == nil {
		return nil, false
	}
	return o.Hugepages, true
}

// HasHugepages returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasHugepages() bool {
	if o != nil && o.Hugepages != nil {
		return true
	}

	return false
}

// SetHugepages gets a reference to the given bool and assigns it to the Hugepages field.
func (o *MemoryZoneConfig) SetHugepages(v bool) {
	o.Hugepages = &v
}

// GetHugepageSize returns the HugepageSize field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetHugepageSize() int64 {
	if o == nil || o.HugepageSize == nil {
		var ret int64
		return ret
	}
	return *o.HugepageSize
}

// GetHugepageSizeOk returns a tuple with the HugepageSize field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetHugepageSizeOk() (*int64, bool) {
	if o == nil || o.HugepageSize == nil {
		return nil, false
	}
	return o.HugepageSize, true
}

// HasHugepageSize returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasHugepageSize() bool {
	if o != nil && o.HugepageSize != nil {
		return true
	}

	return false
}

// SetHugepageSize gets a reference to the given int64 and assigns it to the HugepageSize field.
func (o *MemoryZoneConfig) SetHugepageSize(v int64) {
	o.HugepageSize = &v
}

// GetHostNumaNode returns the HostNumaNode field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetHostNumaNode() int32 {
	if o == nil || o.HostNumaNode == nil {
		var ret int32
		return ret
	}
	return *o.HostNumaNode
}

// GetHostNumaNodeOk returns a tuple with the HostNumaNode field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetHostNumaNodeOk() (*int32, bool) {
	if o == nil || o.HostNumaNode == nil {
		return nil, false
	}
	return o.HostNumaNode, true
}

// HasHostNumaNode returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasHostNumaNode() bool {
	if o != nil && o.HostNumaNode != nil {
		return true
	}

	return false
}

// SetHostNumaNode gets a reference to the given int32 and assigns it to the HostNumaNode field.
func (o *MemoryZoneConfig) SetHostNumaNode(v int32) {
	o.HostNumaNode = &v
}

// GetHotplugSize returns the HotplugSize field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetHotplugSize() int64 {
	if o == nil || o.HotplugSize == nil {
		var ret int64
		return ret
	}
	return *o.HotplugSize
}

// GetHotplugSizeOk returns a tuple with the HotplugSize field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetHotplugSizeOk() (*int64, bool) {
	if o == nil || o.HotplugSize == nil {
		return nil, false
	}
	return o.HotplugSize, true
}

// HasHotplugSize returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasHotplugSize() bool {
	if o != nil && o.HotplugSize != nil {
		return true
	}

	return false
}

// SetHotplugSize gets a reference to the given int64 and assigns it to the HotplugSize field.
func (o *MemoryZoneConfig) SetHotplugSize(v int64) {
	o.HotplugSize = &v
}

// GetHotpluggedSize returns the HotpluggedSize field value if set, zero value otherwise.
func (o *MemoryZoneConfig) GetHotpluggedSize() int64 {
	if o == nil || o.HotpluggedSize == nil {
		var ret int64
		return ret
	}
	return *o.HotpluggedSize
}

// GetHotpluggedSizeOk returns a tuple with the HotpluggedSize field value if set, nil otherwise
// and a boolean to check if the value has been set.
func (o *MemoryZoneConfig) GetHotpluggedSizeOk() (*int64, bool) {
	if o == nil || o.HotpluggedSize == nil {
		return nil, false
	}
	return o.HotpluggedSize, true
}

// HasHotpluggedSize returns a boolean if a field has been set.
func (o *MemoryZoneConfig) HasHotpluggedSize() bool {
	if o != nil && o.HotpluggedSize != nil {
		return true
	}

	return false
}

// SetHotpluggedSize gets a reference to the given int64 and assigns it to the HotpluggedSize field.
func (o *MemoryZoneConfig) SetHotpluggedSize(v int64) {
	o.HotpluggedSize = &v
}

func (o MemoryZoneConfig) MarshalJSON() ([]byte, error) {
	toSerialize := map[string]interface{}{}
	if true {
		toSerialize["id"] = o.Id
	}
	if true {
		toSerialize["size"] = o.Size
	}
	if o.File != nil {
		toSerialize["file"] = o.File
	}
	if o.Mergeable != nil {
		toSerialize["mergeable"] = o.Mergeable
	}
	if o.Shared != nil {
		toSerialize["shared"] = o.Shared
	}
	if o.Hugepages != nil {
		toSerialize["hugepages"] = o.Hugepages
	}
	if o.HugepageSize != nil {
		toSerialize["hugepage_size"] = o.HugepageSize
	}
	if o.HostNumaNode != nil {
		toSerialize["host_numa_node"] = o.HostNumaNode
	}
	if o.HotplugSize != nil {
		toSerialize["hotplug_size"] = o.HotplugSize
	}
	if o.HotpluggedSize != nil {
		toSerialize["hotplugged_size"] = o.HotpluggedSize
	}
	return json.Marshal(toSerialize)
}

type NullableMemoryZoneConfig struct {
	value *MemoryZoneConfig
	isSet bool
}

func (v NullableMemoryZoneConfig) Get() *MemoryZoneConfig {
	return v.value
}

func (v *NullableMemoryZoneConfig) Set(val *MemoryZoneConfig) {
	v.value = val
	v.isSet = true
}

func (v NullableMemoryZoneConfig) IsSet() bool {
	return v.isSet
}

func (v *NullableMemoryZoneConfig) Unset() {
	v.value = nil
	v.isSet = false
}

func NewNullableMemoryZoneConfig(val *MemoryZoneConfig) *NullableMemoryZoneConfig {
	return &NullableMemoryZoneConfig{value: val, isSet: true}
}

func (v NullableMemoryZoneConfig) MarshalJSON() ([]byte, error) {
	return json.Marshal(v.value)
}

func (v *NullableMemoryZoneConfig) UnmarshalJSON(src []byte) error {
	v.isSet = true
	return json.Unmarshal(src, &v.value)
}
