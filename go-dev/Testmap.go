package main

import "fmt"
import "sort"

type M map[string]interface{}

func main() {

	m := make(M)

	//var one uint64 = 1
	m["retry_cnt"] = uint64(1)
	m["retry_cnt"] = m["retry_cnt"].(uint64) + 1

	fmt.Println(m["retry_cnt"])
	fmt.Printf("%v\n", m)

	//迭代不保证顺序

	var unorder map[int]string
	var keys []int
	for k := range unorder {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	for _, k := range keys {
		fmt.Println("Key:", k, "Value:", unorder[k])
	}
}
