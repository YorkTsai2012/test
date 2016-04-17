package main

import(
    "fmt"
    "path/filepath"
)

func main () {
    fmt.Println("xx")
    var str string = "soft.link"
    var link, _ =  filepath.EvalSymlinks(str)
    fmt.Println(link)
}
