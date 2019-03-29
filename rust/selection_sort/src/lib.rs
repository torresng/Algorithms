pub fn selection_sort<T>(arr: &mut [T])
where
    T: Ord,
{
    for j in 0..arr.len() - 1 {
        let mut smallest = j;
        for i in j + 1..arr.len() {
            if arr[i] < arr[smallest] {
                smallest = i;
            }
        }
        arr.swap(j, smallest);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_case() {
        let mut arr: [i32; 6] = [5, 2, 4, 6, 1, 3];
        selection_sort(&mut arr);
        assert_eq!(arr, [1, 2, 3, 4, 5, 6]);
    }
}
