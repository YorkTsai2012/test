package main

import (
	"fmt"
	"os"
	"syscall"
)

func main() {
	logFile, _ := os.OpenFile("/tmp/x", os.O_WRONLY|os.O_CREATE|os.O_SYNC, 0755)
	syscall.Dup2(int(logFile.Fd()), 1)
	syscall.Dup2(int(logFile.Fd()), 2)
	fmt.Printf("Hello from fmt\n")
	panic("Hello from panic\n")
}
