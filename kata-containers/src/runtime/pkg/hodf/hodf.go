// set up a simple package
//
// SPDX-License-Identifier: Apache-2.0
//

package hodf

import (
	"fmt"
	"os"
	"runtime"
	"strings"
	"time"

	"github.com/sirupsen/logrus"
	// "os"
	// "path/filepath"
	// "strings"
)

// init a global file using our package
var HODF_LOG_FILE string = "/tmp/hodf.txt"
var hodf_logger = logrus.New()
var hodf_file *os.File

// CustomFormatter is our custom logrus formatter
type CustomFormatter struct{}

// Format formats the log entry to desired format: "14:18: logrus hello"
func (f *CustomFormatter) Format(entry *logrus.Entry) ([]byte, error) {
	loc := entry.Data["loc"]
	timestamp := time.Now().Format("15:04")
	return []byte(fmt.Sprintf("%s: %s: %s\n", timestamp, loc, entry.Message)), nil
}

// DecorateRuntimeContext appends line, file and function context to the logger
func DecorateRuntimeContext(logger *logrus.Logger) *logrus.Entry {
	// ignoring the file name
	if pc, _, line, ok := runtime.Caller(2); ok {

		fName := runtime.FuncForPC(pc).Name()
		fName = strings.Split(fName, "/")[len(strings.Split(fName, "/"))-1]
		loc := fmt.Sprintf("%s:%d", fName, line)

		return logger.WithField("loc", loc)
	} else {
		return logger.WithField("loc", "unknown")
	}
}

func H_init() {
	fmt.Println("init hodf")
	// init log file
	var err error
	hodf_file, err = os.OpenFile(HODF_LOG_FILE, os.O_CREATE|os.O_WRONLY, 0666)

	if err == nil {
		hodf_logger.SetOutput(hodf_file)
		hodf_logger.SetLevel(logrus.DebugLevel)
		hodf_logger.SetFormatter(&CustomFormatter{})
	} else {
		panic("can not open file")
	}

}

func H_hello() {
	fmt.Println("Hello, World!")
	// add helloworld to a file
	file, err := os.OpenFile("/tmp/helloworld.txt", os.O_CREATE|os.O_WRONLY, 0666)
	if err == nil {
		file.WriteString("Hello, World!\n")
		file.Close()
	}
	H_init()
	H_log("logrus hello")

}

func H_log(info string) {
	Log := DecorateRuntimeContext // so I don't have to type it out every time

	Log(hodf_logger).Debug(info)
}

func H_close() {
	hodf_file.Close()
}
