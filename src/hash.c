#include "header.h"


int binarysearch(int start,int len,char s,char *arr){

  int mid = (start + len)/2;

  if(arr[mid] == s){
    return mid;
  }else{
    if(arr[mid] < s){
      return binarysearch(mid,len+1,s,arr);
    }else{
      return binarysearch(start,mid,s,arr);
    }
  }
}

int hash(char *s){

  char chararr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  int retval = 0;

  int len = strlen(s);

  for(int i = 0 ; i < len;i++){
    retval = retval + binarysearch(0,len,s[i],chararr);
  }

  return retval/len;

}

