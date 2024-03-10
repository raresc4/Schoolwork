from bs4 import BeautifulSoup
import requests
import re
import pandas as pd
import numpy as np
import os
import signal
import sys
from collections.abc import Mapping
import json

#Learned how to do basic webscrapping and how to get requests with python

def get_soup(url):
    r = requests.get(url)
    soup = BeautifulSoup(r.text, "html.parser")
    return soup

soup = get_soup("https://www.cdkeys.com/pc")

oldPrices = soup.select("span[data-price-type='oldPrice'] span")

products = soup.select("li.product-item")

for i in range(len(products)): 
   prod = json.loads(products[i]["data-impression"])
   print(f"{prod['name']} - ${prod['price']} - {oldPrices[i].text}")
