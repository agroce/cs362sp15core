import sys

f1 = sys.argv[1]
f2 = sys.argv[2]

text1 = []
text2 = []
for l in open(f1):
    text1.append(l)
for l in open(f2):
    text2.append(l)

shortest = min(len(text1),len(text2))
for i in xrange(0,shortest):
    if (text1[i] != text2[i]):
        print "FIRST DIFFERENCE:"
        print text1[i]
        print "    VS"
        print text2[i]
        break
    if "bought" in text1[i] or "played" in text1[i] or "end" in text1[i]:
        print text1[i],
