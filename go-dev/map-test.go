

package main

import (
    "strings"
    "golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
    var m = make(map[string]int)
    var words = strings.Fields(s)
    for _, v := range words {
        /*
        _, ok := m[v]
        if !ok {
            m[v] = 1
        } else {
            m[v]++
        }
        */
        m[v]++
    }
    return m
}

func main() {
    wc.Test(WordCount)
}
