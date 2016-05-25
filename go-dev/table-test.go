

package main

import (
    "fmt"
)

func main() {
    //var m [4][]uint8
    var m = make([][]uint8, 4)
    for i := 0; i < 4; i++ {
        m[i] =  make([]uint8, 4)
        for j := 0; j < 4; j++ {
            m[i][j] = uint8((i+1)*(j+1))
            fmt.Printf("%v\t",m[i][j])
        }
        fmt.Println()
    }
}
