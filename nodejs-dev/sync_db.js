

db.system.js.save({
     _id : "getNextSequence" ,
     value :  function (name) {
        var ret = db.counters.findAndModify({
            query: { _id: name },
            update: { $inc: { seq: 1 } },
            new: true,
            upsert: true
        });
        return ret.seq;
    }
});
