package main

import (
	"os"

	"io"

	log "github.com/sirupsen/logrus"
)

func init() {
	file, err := os.OpenFile("log.txt", os.O_CREATE|os.O_WRONLY, 0666)
	if err == nil {
		log.SetOutput(file)
	}
	wrt := io.MultiWriter(os.Stdout, file)
	log.SetOutput(wrt)

	// Only log the warning severity or above.
	// log.SetLevel(log.WarnLevel)
}

func main() {
	var name = "kata-debug"

	contextLogger := log.WithFields(log.Fields{
		"username":    "sirupsen",
		"environment": name,
	})

	contextLogger.Info("This is a structured info message")
	// change the name for the next log message
	contextLogger.Warn("This is a structured warning message")
}
