import sys
import collections
# Python 3
ARRAY = ['Mary', 'had', 'a', 'little', 'lamb', 'its', 'fleece', 'was', 'white', 'as', 'snow', 'And', 'everywhere', 'that', 'Mary', 'went', 'the', 'lamb', 'was', 'sure', 'to', 'go', 'It', 'followed', 'her', 'to', 'school', 'one', 'day', 'which', 'was', 'against', 'the', 'rule', 'It', 'made', 'the', 'children', 'laugh', 'and', 'play', 'to', 'see', 'a', 'lamb', 'at', 'school', 'And', 'so', 'the', 'teacher', 'turned', 'it', 'out', 'but', 'still', 'it', 'lingered', 'near', 'And', 'waited', 'patiently', 'about', 'till', 'Mary', 'did', 'appear', 'Why', 'does', 'the', 'lamb', 'love', 'Mary', 'so', 'the', 'eager', 'children', 'cry', 'Why', 'Mary', 'loves', 'the', 'lamb', 'you', 'know', 'the', 'teacher', 'did', 'reply']

def make_hash(array, n):
	hash_array = collections.defaultdict(dict)
	for i in range(len(array) - n):
		hash_key = ' '.join(array[i : i + n])
		this = array[i + n]
		if this not in hash_array[hash_key]:
			hash_array[hash_key][this] = 1
		else:
			hash_array[hash_key][this] += 1
	return hash_array

def main():
	indexes = {}
	with open(sys.argv[1], 'r') as this_file:
		for line in this_file:
			n = int(line.strip().split(',')[0])-1
			word = line.strip().split(',')[1]
			if n not in indexes: indexes[n] = make_hash(ARRAY, n)
			answer = list(indexes[n][word].items())
			total = sum(indexes[n][word].values())
			answer.sort(key=lambda tup: tup[0])
			answer.sort(key=lambda tup: tup[1], reverse = True)
			final_output = []
			for k in answer:
				a = float(k[1]/total)
				final_output.append(k[0] + ',' + ("%.3f" % a))
			print(';'.join(final_output))

if __name__ == '__main__':
	main()















