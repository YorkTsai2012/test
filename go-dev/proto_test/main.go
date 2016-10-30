package main

    import (
        "log"
        "github.com/golang/protobuf/proto"
        "example"
    )

    func main() {
        test := &example.Test {
            Label: proto.String("hello"),
            Type:  proto.Int32(17),
            Reps:  []int64{1, 2, 3},
            Optionalgroup: &example.Test_OptionalGroup {
                RequiredField: proto.String("good bye"),
            },
        }
        data, err := proto.Marshal(test)
        if err != nil {
            log.Fatal("marshaling error: ", err)
        }
        log.Printf("%q", data)
        newTest := &example.Test{}
        err = proto.Unmarshal(data, newTest)
        if err != nil {
            log.Fatal("unmarshaling error: ", err)
        }
        // Now test and newTest contain the same data.
        if test.GetLabel() != newTest.GetLabel() {
            log.Fatalf("data mismatch %q != %q", test.GetLabel(), newTest.GetLabel())
        }
        // etc.
        log.Printf("%s", newTest.GetLabel())
        log.Printf("%d", newTest.GetType())
        var t []int64 = newTest.GetReps()
        log.Printf("%d,%d,%d", t[0], t[1], t[2])
    }
