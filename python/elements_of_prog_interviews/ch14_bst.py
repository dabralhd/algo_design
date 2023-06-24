from sortedcollections import SortedList

if __name__=='__main__':
    sl = SortedList([(1, 'jan'), (14, 'march'), (2, 'aug'), (89, 'may'), (-1, 'december')])
    print(sl[1][1])
