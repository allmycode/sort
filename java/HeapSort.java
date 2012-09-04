import java.util.*;

public class HeapSort {

    static long as = 0;
    static long cmp = 0;
    public static void main(String[] args) {
        int[] a = new int[10000000];
        Random r = new Random(System.currentTimeMillis());
        for (int i = 0; i < a.length; i++)
            a[i] = r.nextInt();
        long start = System.currentTimeMillis();
        heapsort(a);
        System.out.println("Time is: " + ((double)System.currentTimeMillis() - start)/1000 + " " + as + " " + cmp + " " +
                           (as + cmp));
    }

    public static void heapsort(int[] a) {
         build_max_heap(a);
         int size = a.length;
         for (int i = a.length-1; i > 0; i--) {
             as += 3;
             int t = a[0];
             a[0] = a[i];
             a[i] = t;
             size--;
             max_heapify(a, size, 0);
         }
    }

    public static void max_heapify(int[] a, int size, int i) {
         int left =  (i + 1) * 2 - 1;
         int right = (i + 1) * 2;
         int largest = i;
         if (left < size && a[left] > a[largest]) {
             largest = left;
             cmp++;
         }
         if (right < size && a[right] > a[largest]) {
             cmp++;
             largest = right;
         }
         if (largest != i) {
             int t = a[i];
             a[i] = a[largest];
             a[largest] = t;
             as += 3;
             max_heapify(a, size, largest);
         }
    }

    public static void build_max_heap(int[] a) {
        for (int i = a.length / 2; i >= 0; i--) {
            max_heapify(a, a.length, i);
        }
    }

}
