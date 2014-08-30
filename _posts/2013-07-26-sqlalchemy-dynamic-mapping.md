---
layout: post
title: "sqlalchemy dynamic mapping"
description: ""
category: 
tags: []
---
{% include JB/setup %}
#sqlalchemy动态映射
代码如下:

    from sqlalchemy import *
    from sqlalchemy.orm import *
    
    metadata=MetaData(create_engine("sqlite://",echo=True)
    t1=Table("t1",metadata,Column('id',Integer,primary_key=True))
    t2=Table("t2",metadata,Column("id",Integer,primary_key=True))
    metadata.create_all()
    
    def map_class_to_some_table(cls,table,entity_name,**kw):
        newcls=type(entity_name,(cls,),{})
        mapper(newcls,table,**kw)
        return newcls
       
    class Foo(object):
        pass
    
    T1Foo=map_class_to_some_table(Foo,t1,"T1Foo")
    T2Foo=map_class_to_some_table(Foo,t2,"T2Foo")
    
    sess=sessionmaker()()
    sess.add_all([T1Foo(),T1Foo(),T2Foo(),T1Foo()])
    print sess.query(T1Foo).all()
    print sess.query(T2Foo).all()

