package main

import (
    "crypto/tls"
    "fmt"
    "io/ioutil"
    "net/http"
)

func main() {
    tr := &http.Transport{
        TLSClientConfig:    &tls.Config{InsecureSkipVerify: true},
    }
    client := &http.Client{Transport: tr}
    resp, err := client.Get("https://key-value.ufile-webuploader.ucloud.cn/example.txt")

    if err != nil {
        fmt.Println("error:", err)
        return
    }
    defer resp.Body.Close()
    body, err := ioutil.ReadAll(resp.Body)
    fmt.Println(string(body))
}
