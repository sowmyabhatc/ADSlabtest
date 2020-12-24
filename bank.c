#include<stdint.h>
#include<assert.h>
#include<string.h>
#include "bank.h"

Customer c(char* name,int32_t age,char* pan,char acc_type,char* phone number,int32_t amount){
Customer c={name,age,NULL,acc_type,phone number,amount};
return c;

}

Account  a(char bankcode,char areacode,char acc_type,int32_t acct_no){
Account a={bancode,areacode,acc_type,1000};
return a;
}

Queue queue_new(uint32_t size){
size=(size>0  && size<n )? size:n;
Queue q1={size,0,0,0,{0}};
return q1;
}

uint8_t  queue_full(Queue *q){
assert(q!=NULL);
return (q->count == q->size);

}

uint8_t  queue_empty(Queue *q){
assert(q!=NULL);
return (q->count ==0);
}

Queue*  queue_add(Queue *q,Customer *c,QueueResult *res){
Account a;
assert(q!=NULL);

if(q->count<q->size){
    q->data[q->rear]=*c;
    q->rear=((q->rear +1)%(q->size));
    ++q->count
    a[3]+=1;
    res->status=QUEUE_OK;
}
else{
    res->status=QUEUE_FULL;

}
return q;
}

Queue* queue_delete(Queue *q, QueueResult *res){
assert(q!=NULL);
if (q->count !=0){
    res->amount=q->data[q->front].amount;
    q->front=(q->front +1)%q->size;
    --q->count;
    res->status=QUEUE_OK;

}
else{
    res->status=QUEUE_EMPTY;
}
return q;
}


Queue*    credit(Queue *q,Customer *c,int32_t depositamount,QueueResult *res){
assert( q != NULL );
    int32_t i = q->front;

    for( i = q->front; i <= q->size ; i++ ){
        if (q->data[i].name == c->name ){
            q->data[i].amount += depositamount;


        }
    }
    res->status=CREDIT;
    res->credit_count+=1;
    return q;
}

Queue* debit(Queue* q, Customer *c, QueueResult *res,int32_t amt){
    assert( q != NULL);
    int32_t i = q->front;
    if((strcmp(q->data->acc_type,"SA")==0) && res->debit_count<10 && res->amount>=0){  //Student account and maximum of 10 debit transactions
      for( i = q->front; i <= q->size ; i++ ){
        if (q->data[i].name == c->name ){
            q->data[i].depositamount -= amt;

        }
    }
    }
    else if(res->debit_count<5 ){   //other accounts
     for( i = q->front; i <= q->size ; i++ ){
        if (q->data[i].name == c->name && res->amount>=2000){
            q->data[i].depositamount -= amt;

        }
        else{
            q->data[i].depositamount -= 1000;
        }

    }
    res->status=DEBIT;
    res->debit_count+=1;


    return q;
}

uint32_t    balancenquiry(const Queue *q,char* name){
   assert( q != NULL);
   for ( i = q->front; i <= q->size; i++){
        if (strcmp(q->data->name,name)==0){
            return q->data[i].amount;
        }
        else{
            return 0;
        }
    }

}


