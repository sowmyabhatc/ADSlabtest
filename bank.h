#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include "appconst.h"

typedef struct _cust_ Customer;
struct _cust_{
char* name;
int32_t age;
int32_t pan;
char acc_type[ACCT_TYPE];
char* phone number;
int32_t amount;
};



typedef struct _acc_ Account;
struct _account_{
char bankcode[BANK_CODE ];
char areacode[AREA_CODE];
char acc_type[ACCT_TYPE];
int32_t acct_no[ACCT_NO];
};


typedef struct _queue_  Queue;

struct _queue_{
uint32_t   size;
uint32_t   count;
uint32_t   rear;
uint32_t   front;
Customer    data[n];
};


typedef struct  _queue_result  QueueResult;

struct _queue_result{
Customer    data[n];
uint32_t  status;
uint32_t  tstatus;
int32_t   amount;
int32_t credit_count;
int32_t debit_count;
};



Customer c(char* name,int32_t age,char* pan,char acc_type,char* phone number,int32_t amount);
Account  a(char bankcode,char areacode,char acc_type,char acct_no);
Queue     queue_new(uint32_t  size);
uint8_t   queue_full(Queue *q);
uint8_t   queue_empty(Queue *q);
Queue*    queue_add(Queue *q,Customer *c,QueueResult *res);
Queue*    queue_delete(Queue *q,QueueResult *res);
Queue*    credit(Queue *q,Customer *c,int32_t depositamount,QueueResult *res);
Queue*    debit(Queue* q, Customer *c, QueueResult *res,int32_t amt);
uint32_t  balancenquiry(const Queue *q,char* name);
uint32_t  queue_length(Queue *q);


#endif // BANK_H_INCLUDED
