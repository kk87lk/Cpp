Position BinarySearch(List L, ElementType X)
{
  int top = 0, buttom = 1, mid = 0;
  top = L->Last;
  mid = top / 2;
  while (buttom < top)
  {
    if (L->Data[mid] == X) return mid;
    else if (L->Data[mid] < X ) buttom = mid + 1;
    else if (L->Data[mid] > X ) top = mid - 1;
    mid = (top + buttom) / 2;
  }
  return NotFound;
}