package main

import (
	"fmt"
	"strings"
)

func main() {
	//var url_str string = "globalv3.dl.ufileos.com"
	var url_str string = "globalv3.xx.ufileos.com"
	pos := strings.Index(url_str, ".dl.ufileos.com")
	if pos != -1 {
		fmt.Println("bucket", url_str[:pos])
	}
}
