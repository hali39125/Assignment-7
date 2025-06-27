class StatisticsCalculator:
    def __init__(self, lst):
        self.lst = lst

    def calculate_mean(self):
        return sum(self.lst) / len(self.lst)

    def calculate_median(self):
        sorted_lst = sorted(self.lst)
        mid = len(self.lst) // 2
        if len(self.lst) % 2 == 0:
            return (sorted_lst[mid - 1] + sorted_lst[mid]) / 2.0
        else:
            return sorted_lst[mid]

    def calculate_mode(self):
        count = {}
        for num in self.lst:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1
        max_count = max(count.values())
        mode = [num for num, freq in count.items() if freq == max_count]
        return mode[0]

# Main function
if __name__ == "__main__":
    lst = [1, 2, 3, 4, 5]
    calculator = StatisticsCalculator(lst)
    mean = calculator.calculate_mean()
    median = calculator.calculate_median()
    mode = calculator.calculate_mode()
    print(f"Mean: {mean:.2f}")
    print(f"Median: {median:.2f}")
    print(f"Mode: {mode}")