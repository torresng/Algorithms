pub fn insertion_sort<T>(arr: &mut [T])
where
    T: Ord,
{
    for j in 1..arr.len() {
        for i in (0..j).rev() {
            if arr[i] > arr[i + 1] {
                arr.swap(i, i + 1)
            } else {
                break;
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_case() {
        let mut arr: [i32; 6] = [5, 2, 4, 6, 1, 3];
        insertion_sort(&mut arr);
        assert_eq!(arr, [1, 2, 3, 4, 5, 6]);
    }
}
