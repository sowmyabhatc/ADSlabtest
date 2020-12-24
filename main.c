#include <stdio.h>
#include <stdlib.h>
#inlude <stdint.h>
#include "bank.h"
#include "appconst.h"

void test_queue(){
Queue q1=queue_new(3);
Queue *q=&q1;
assert(queue_empty(q));
}

void test_queueadd(){
Queue q1=queue_new(10);
Queue *q=&q1;
QueueResult res;

Customer c1=c{"abc",20,"2000","CA","201051018",2000};
Customer c2=c{"bcd",22,"2001","SA","201051019",20000};
Customer c3=c{"def",24,"2002","CA","201051020",3000};
Customer c4=c{"efg",28,"2003","CA","201051020",3000};
Customer c5=c{"hij",30,"2004","CA","201051020",3000};
Account a1={22,43,"SB",}
q=queue_add(q,&c1,&res);
q=queue_add(q,&c2,&res);
q=queue_add(q,&c3,&res);
q=queue_add(q,&c4,&res);
q=queue_add(q,&c5,&res);

q=credit(q,&c1,2000,&res);
assert(q.data[1].amount==4000);
assert(res.credit_count==1);

q=debit(q,&c1,&res,500);
assert(res.debit_count==1);
assert(res.data[1].acc_type=="CA");


assert(queue_length(q)==3);
assert(res.status ==QUEUE_FULL);
assert(queue_full(q));



}




int main()
{
   // printf("Hello world!\n");
   test_queueadd();
    return 0;
}
