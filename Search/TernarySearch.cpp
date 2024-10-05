int low = 1, high = n, res;

int calc(int x){
	
}
 
void calc(int low, int high){
	if(low == high){
		res = calc(low);
		return;
	}
	int mid1 = low + (high - low) / 3;
	int mid2 = high - (high - low) / 3;
	int val1 = calc(mid1);
	int val2 = calc(mid2);
	if(val1 <= val2){
		calc(low, mid2 - 1);
	}
	else{
		calc(mid1 + 1, high);
	}
}

calc(1, n)