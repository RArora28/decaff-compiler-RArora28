class Program {
	int main() {
		int n = read(); 
		int arr[n]; 
		for (i = 0, n) {
			arr[i] = read(); 
		}
		int search = read(); 
		bool found = false; 
		int idx = n + 1; 
		for (i = 0, n) {
			if (arr[i] == search) {
				found = true; 
				idx = i; 
				break; 
			}
		}
		if (found) {
			callout("printf", "%d found at index %d.\n", search, idx); 
		} else {
			callout("printf", "%d not found.\n", search, idx); 
		}
		return 0; 
	}
}