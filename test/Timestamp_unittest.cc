#include <base/Timestamp.h>
#include <vector>
#include <stdio.h>

using muduo::Timestamp;

void passByConstReference(const Timestamp& x)
{
  printf("ConstReference %s\n", x.toString().c_str());
}

void passByValue(Timestamp x)
{
  printf("ByValue %s\n", x.toString().c_str());
}

void benchmark()
{
  const int kNumber = 1000*1000;

  std::vector<Timestamp> stamps;
  stamps.reserve(kNumber);
  for (int i = 0; i < kNumber; ++i)
  {
    stamps.push_back(Timestamp::now());
  }
  printf("benchmark front %s\n", stamps.front().toString().c_str());
  printf("benchmark back %s\n", stamps.back().toString().c_str());
  printf("benchmark Diff %f\n", timeDifference(stamps.back(), stamps.front()));

  int increments[100] = { 0 };
  int64_t start = stamps.front().microSecondsSinceEpoch();
  for (int i = 1; i < kNumber; ++i)
  {
    int64_t next = stamps[i].microSecondsSinceEpoch();
    int64_t inc = next - start;
    start = next;
    if (inc < 0)
    {
      printf("reverse!\n");
    }
    else if (inc < 100)
    {
      ++increments[inc];
    }
    else
    {
      printf("big gap %d\n", static_cast<int>(inc));
    }
  }

  for (int i = 0; i < 100; ++i)
  {
    printf("%2d: %d\n", i, increments[i]);
  }
}

int main()
{
  Timestamp now(Timestamp::now());
  printf("now to string %s\n", now.toString().c_str());
  printf("now to toFormattedString %s\n", now.toFormattedString().c_str());
  passByValue(now);
  passByConstReference(now);
  benchmark();

  getchar();
}

