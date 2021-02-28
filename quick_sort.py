def partition(a,i,j):
    pi=j
    left=i
    for k in range(i,j):
        if a[k]<a[pi]:
            a[k],a[left]=a[left],a[k]
            left=left+1
    a[left],a[pi]=a[pi],a[left]
    return left


def quicksort(ar,l,h):
    if l < h:
        pi=partition(ar,l,h)
        quicksort(ar,l,pi-1)
        quicksort(ar,pi+1,h)


#quicksort
arr=[1,2,9,4,5,3,20,19]
n=len(arr)
quicksort(arr,0,n-1)
print("sorted array is:")
for i in range(n):
    print(arr[i])