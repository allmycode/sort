package sorting;

import java.util.Random;
import java.util.Arrays;
import java.util.Calendar;

public class MergeSort {

	private static void bubblesort(int[] a, int n) {

		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(a[j]<a[i]) {
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}

	private static void insertionsort(int[] arr,int n) 
	{ 
		for (int i = 1; i < n; ++i) { 
			int key = arr[i]; 
			int j = i - 1; 

			while (j >= 0 && arr[j] > key) { 
				arr[j + 1] = arr[j]; 
				j = j - 1; 
			} 
			arr[j + 1] = key; 
		} 
	} 

	private static void selectionSort(int[] arr,int n){  
		for (int i = 0; i < n - 1; i++)  
		{  
			int index = i;  
			for (int j = i + 1; j < n; j++){  
				if (arr[j] < arr[index]){  
					index = j;//searching for lowest index  
				}  
			}  
			int smallerNumber = arr[index];   
			arr[index] = arr[i];  
			arr[i] = smallerNumber;  
		}  
	}  

	private static void mergesort(int[] arr, int start, int end) {
		if(start<end) {

			int mid = (start+end)/2;

			mergesort(arr,start,mid);  // sort the first part
			mergesort(arr,mid+1,end);  // sort the second part

			merge(arr,start,mid,end);
		}
	}

	private static void merge(int[] arr, int start, int mid, int end) {

		int p =start ,q=mid+1,k=0;

		int a[] = new int[end-start+1];

		for( int i=start; i <= end ; i++ ) {
			if(p>mid) {     //checks if first part comes to an end or not .
				a[k++]=arr[q++];
			}
			else if(q>end) {   //checks if second part comes to an end or not .
				a[k++]=arr[p++];
			}
			else if (arr[p]<arr[q]) {
				a[k++]=arr[p++];
			}
			else {
				a[k++]=arr[q++];
			}
		}

		// updating in the originastartarray ie arr[]

		for(int i=0;i<k;i++) {
			arr[start++]=a[i];
		}

	}

	private static void quicksort(int[] arr, int low, int high) {

		if(low<high) {
			int pivot = partition(arr,low,high);

			quicksort(arr, low , pivot-1 );
			quicksort(arr, pivot+1 , high);
		}

	}

	private static int partition(int[] arr, int low, int high) {

		// taking the position of pivot as last element
		int pivot = arr[high];  
		int i = (low-1); 

		for (int j=low; j<high; j++) 
		{ 

			if (arr[j] < pivot) 
			{ 
				i+=1;
				// swap arr[i] arr[j] 

				int temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp; 

			} 
		} 

		// swap arr[i+1]  arr[high]
		int temp = arr[i+1]; 
		arr[i+1] = arr[high]; 
		arr[high] = temp; 

		return i+1; 
	}

	private static void heapsort(int arr[], int n) 
	{ 
		for (int i = n / 2 - 1; i >= 0; i--) 
			heapify(arr, n, i); 
		for (int i=n-1; i>=0; i--) 
		{ 
			int temp = arr[0]; 
			arr[0] = arr[i]; 
			arr[i] = temp; 

			heapify(arr, i, 0); 
		} 
	} 

	private static void heapify(int arr[], int n, int i) 
	{ 
		int largest = i; // Initialize largest as root 
		int l = 2*i + 1; // left = 2*i + 1 
		int r = 2*i + 2; // right = 2*i + 2 

		if (l < n && arr[l] > arr[largest]) 
			largest = l; 

		if (r < n && arr[r] > arr[largest]) 
			largest = r; 
		if (largest != i) 
		{ 
			int swap = arr[i]; 
			arr[i] = arr[largest]; 
			arr[largest] = swap; 

			heapify(arr, n, largest); 
		} 
	} 

	private static int getMax(int arr[], int n) 
	{ 
		int mx = arr[0]; 
		for (int i = 1; i < n; i++) 
			if (arr[i] > mx) 
				mx = arr[i]; 
		return mx; 
	} 

	private static void countSort(int arr[], int n, int exp) 
	{ 
		int output[] = new int[n];  
		int i; 
		int count[] = new int[10]; 
		Arrays.fill(count,0); 

		for (i = 0; i < n; i++) 
			count[ (arr[i]/exp)%10 ]++; 

		for (i = 1; i < 10; i++) 
			count[i] += count[i - 1]; 

		for (i = n - 1; i >= 0; i--) 
		{ 
			output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
			count[ (arr[i]/exp)%10 ]--; 
		} 

		for (i = 0; i < n; i++) 
			arr[i] = output[i]; 
	} 

	private static void radixsort(int arr[], int n) 
	{ 
		int m = getMax(arr, n); 

		for (int exp = 1; m/exp > 0; exp *= 10) 
			countSort(arr, n, exp); 
	} 

	private static int shellsort(int arr[]) 
	{ 
		int n = arr.length; 

		for (int gap = n/2; gap > 0; gap /= 2) 
		{ 

			for (int i = gap; i < n; i += 1) 
			{ 
				int temp = arr[i]; 

				int j; 
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
					arr[j] = arr[j - gap]; 

				arr[j] = temp; 
			} 
		} 
		return 0; 
	} 


	private static int[] bucketsort(int[] sequence, int maxValue) 
	{
		// Bucket Sort
		int[] Bucket = new int[maxValue + 1];
		int[] sorted_sequence = new int[sequence.length];

		for (int i = 0; i < sequence.length; i++)
			Bucket[sequence[i]]++;

		int outPos = 0;
		for (int i = 0; i < Bucket.length; i++)
			for (int j = 0; j < Bucket[i]; j++)
				sorted_sequence[outPos++] = i;

		return sorted_sequence;
	}

	private static int maxValue(int[] sequence) 
	{
		int maxValue = 0;
		for (int i = 0; i < sequence.length; i++)
			if (sequence[i] > maxValue)
				maxValue = sequence[i];
		return maxValue;
	}
	
	public static void main(String[] args) {

		Random rand = new Random();
		// size of the array 
		int n=1000;

		int a[] = new int[n];
		int b[] = new int[n];
		int c[] = new int[n];
		int d[] = new int[n];
		int e[] = new int[n];
		int f[] = new int[n];
		int g[] = new int[n];
		int h[] = new int[n];
		int k[] = new int[n];

		// creating random numbered arrays 
		for(int i=0;i<n;i++) {
			a[i] = rand.nextInt(90000000);
			b[i] = a[i];
			c[i] = a[i];
			d[i] = a[i];
			e[i] = a[i];
			f[i] = a[i];
			g[i] = a[i];
			h[i] = a[i];
			k[i] = a[i];
		}

		// bubble sort  
		Calendar a1 = Calendar.getInstance();
		long t1 = a1.getTimeInMillis();
		bubblesort(a,n);
		Calendar a2 = Calendar.getInstance();
		System.out.println("bubble sort "+(a2.getTimeInMillis()-t1)/1000.0+" sec ");

		// selection sort  
		Calendar b1 = Calendar.getInstance();
		long t2 = b1.getTimeInMillis();
		selectionSort(b, n);
		Calendar b2 = Calendar.getInstance();
		System.out.println("selection sort "+(b2.getTimeInMillis()-t2)/1000.0+" sec ");

		// insertion sort  
		Calendar c1 = Calendar.getInstance();
		long t3 = c1.getTimeInMillis();
		insertionsort(c, n);
		Calendar c2 = Calendar.getInstance();
		System.out.println("insertion sort "+(c2.getTimeInMillis()-t3)/1000.0+" sec ");

		// merge sort  
		Calendar d1 = Calendar.getInstance();
		long t4 = d1.getTimeInMillis();
		mergesort(d, 0, n-1);
		Calendar d2 = Calendar.getInstance();
		System.out.println("merge sort "+(d2.getTimeInMillis()-t4)/1000.0+" sec ");

		// quick sort  
		Calendar e1 = Calendar.getInstance();
		long t5 = e1.getTimeInMillis();
		quicksort(e, 0, n-1);
		Calendar e2 = Calendar.getInstance();
		System.out.println("quick sort "+(e2.getTimeInMillis()-t5)/1000.0+" sec ");

		// heap sort  
		Calendar f1 = Calendar.getInstance();
		long t6 = f1.getTimeInMillis();
		heapsort(f,n);
		Calendar f2 = Calendar.getInstance();
		System.out.println("heap sort "+(f2.getTimeInMillis()-t6)/1000.0+" sec ");

		// radix sort  
		Calendar g1 = Calendar.getInstance();
		long t7 = g1.getTimeInMillis();
		radixsort(g, n);
		Calendar g2 = Calendar.getInstance();
		System.out.println("radix sort "+(g2.getTimeInMillis()-t7)/1000.0+" sec ");

		// shell sort  
		Calendar h1 = Calendar.getInstance();
		long t8 = h1.getTimeInMillis();
		shellsort(h);
		Calendar h2 = Calendar.getInstance();
		System.out.println("shell sort "+(h2.getTimeInMillis()-t8)/1000.0+" sec ");

		// bucket sort  
		Calendar k1 = Calendar.getInstance();
		long t9 = k1.getTimeInMillis();
		int maxValue = maxValue(k);
		bucketsort(k, maxValue);
		Calendar k2 = Calendar.getInstance();
		System.out.println("bucket sort "+(k2.getTimeInMillis()-t9)/1000.0+" sec ");

	}



}
