package main

import (
	"errors"
	"fmt"
)

func printResult(pErr *error) {
	var result string
	if *pErr != nil {
		result = "FAILED"
	} else {
		result = "SUCCESS"
	}
	fmt.Printf("result:%v|err:%v\n", result, *pErr)
}

func main() {
	condition := true
	var err error
	if condition {
		defer printResult(&err)
	}
	fmt.Println("hello")
	err = errors.New("Error Backend")
}
