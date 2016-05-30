package main

import (
	"fmt"
)

var anything interface{} = "string"
var moreAnything interface{} = 123

func main() {
	switch v := anything.(type) {
	case string:
		fmt.Println(v)
	case int, int32, int64:
		fmt.Println(v)
	case uint32, uint64:
		fmt.Println(v)
	default:
		fmt.Println("unknown")
	}

}
