# from urllib.request import urlopen
# from bs4 import BeautifulSoup
# html = urlopen("https://www.google.com/search?q=machine+learning")
# soup = BeautifulSoup(html, 'html.parser')
# print(soup.prettify())

from googlesearch import search

for url in search('machine learning', tld='com.pk', lang='es', stop=5):
    print(url)