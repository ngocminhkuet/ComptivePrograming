int low = 1, high = n, res;

bool check(int x){

}

while(low <= high){
    int mid = (low + high) >> 1;
    if(check(mid)){
        res = mid;
        low = mid + 1;
    }
    else high = mid - 1;
}
