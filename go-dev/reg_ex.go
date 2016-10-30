package main

import (
	"fmt"
	"regexp"
)

func main() {
	matched, err := regexp.MatchString("bar/.*.txt", "bar/123.txt")
	fmt.Println(matched, err)
}
