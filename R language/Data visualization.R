library(tidyverse)
x <- read.csv("superstore (1).csv",sep="|")
write_csv(x,"alltable.csv")

#แบ่งตารางให้ดูง่าย
y <- separate(x,Order.Date,c("Year","Month","Time"),sep = "-")
write_csv(y,"Years.csv")

#table1 (monthly sales)
sell <- y%>%
  group_by(Year,Month)%>%
  summarise(sumsell = sum(Profit))
ggplot(sell)+geom_col(mapping = aes(x = Year,y = sumsell,fill = Month),position = 'dodge')
  
#table2 (bestseller of years)
BOY <- y%>%
  group_by(Year,Category) %>%
  summarise(sumbestseller = sum(Profit))
ggplot(BOY)+geom_col(mapping = aes(x = Year,y = sumbestseller,fill = Category),position = 'dodge')

#table3 (Most order of city)
BSC <- y%>%
  group_by(Region) %>%
  summarise(bestorder = sum(Quantity))
ggplot(BSC)+geom_col(mapping = aes(x =Region ,y = bestorder),position = 'dodge')
