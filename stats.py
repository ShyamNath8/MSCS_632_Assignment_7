class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = numbers

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        nums = sorted(self.numbers)
        n = len(nums)
        mid = n // 2
        if n % 2 == 0:
            return (nums[mid - 1] + nums[mid]) / 2
        return nums[mid]

    def mode(self):
        frequency = {}
        for num in self.numbers:
            frequency[num] = frequency.get(num, 0) + 1

        max_freq = max(frequency.values())
        return [num for num, freq in frequency.items() if freq == max_freq]


if __name__ == "__main__":
    data = [4, 1, 2, 2, 5, 3, 3]
    calc = StatisticsCalculator(data)

    print("Mean:", calc.mean())
    print("Median:", calc.median())
    print("Mode(s):", calc.mode())
