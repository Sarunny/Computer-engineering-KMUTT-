install.packages("tidyverse")
library(dplyr)
library(purrr)
library("ggplot2")

hotel1 <- read.csv("Hotel_Reviews.csv")

hotel <- hotel1 %>% distinct(Hotel_Name, .keep_all = TRUE)

#แยกที่อยู่แต่ละแถวแบ่งเป็ฯแต่ละอันของทุกแถว
test <- strsplit(hotel[,1],split=" ")
test

#สร้างเป็น list เอาแค่ตัวสุดท้ายที่เป็นประเทศ
list <- map(test,last)
list

#เปลี่ยนจาก list เป็น dataframeเพื่อใช้กราฟของอาจารย์ได้
install.packages("reshape2")
require(reshape2)
h <- do.call(cbind, list)
hotel_c <- melt(h)

#ใส่ชื่อคอลัมให้ dataframe
## rename variables so they look nicer on plots
names(hotel_c) <- c("idk","id","country")

#plot กราฟ
options(scipen = 999)
hotel_c %>%
  ggplot() + geom_bar(mapping = aes(x = country,fill = country))

#สรุปข้อมูล
hotel_c %>% 
  group_by(country) %>%
  summarise(total = n())
