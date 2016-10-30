package main

import (
	"fmt"
	"gopkg.in/mgo.v2"
	"gopkg.in/mgo.v2/bson"
	"log"
)

type Person struct {
	Name  string
	Phone string
}

func main() {
	session, err := mgo.Dial("127.0.0.1:27017")
	if err != nil {
		panic(err) //panic 在服务端程序中似乎不能随便用的
	}
	defer session.Close()

	// Optional. Switch the session to a monotonic behavior.
	session.SetMode(mgo.Monotonic, true)

	c := session.DB("test").C("people")
	err = c.Insert(&Person{"Ale", "+55 53 8116 9639"},
		&Person{"Cla", "+55 53 8402 8510"})
	if err != nil {
		log.Fatal(err)
        return
	}

	result := Person{}
	//err = c.Find(bson.M{"name": "Ale"}).One(&result)
/*
	if err != nil {
		log.Fatal(err)
	}
*/
    //批量查询 Skip + Limit
    iter := c.Find(bson.M{}).Skip(1).Limit(2).Iter()
    for iter.Next(&result) {
        fmt.Printf("Result: %v\n", result.Name)
    }
    if err := iter.Close(); err != nil {
        log.Fatal(err)
        return
    }

	fmt.Println("Phone:", result.Phone)
    //cusor?
}
