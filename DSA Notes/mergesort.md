# mergesort

//Algorithm
//**Merging**
//if two lists are already sortd , it is compared i with j , and result is combined in K array whcih is also sorted
// THETA( m + n ) - moving m and n to K array
//i=1,j=1,k=1;
// while(i<=n & j<=m)
// if(A[i]>B[j])
//     C[k++]=A[i++];
// else
//     C[k++]=B[i++];
// *******copying remaining elements*****
// for(;i<=n;i++)
// c[k++]=A[i];
// for(;j<=mi++)
// c[k++]=B[i];

**2 way merging vs merging**
# 2 way merging : loops
# merge sort : recursively

In merge sort the array is divided into n lists, they mergeing is used in a 2 way method
![Merge Sort](image-3.png)

# Post order merging
//mergesort(l,h)
// if l<h;
// mid=1+h/2
// mergesort(l,mi)
// mergesort(mid+1,h)
// merge(l,mmid,h)


# Time Complexity

T(n) = Ø(nlogn)

