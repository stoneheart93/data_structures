1. Write a program to calculate pow(x, y)

int power(int x, int y)
{
	if(y == 0)
		return 1;
	if(y == 1)
		return x;

	int cache = power(x, y / 2);

	if(y % 2 == 0)
		return cache * cache;
	else
		return x * cache * cache;
}

Time complexity = O(log y)

2. Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?

void delNode(struct node* ptr)
{
	struct node* temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	free(temp);
}

Time complexity = O(1)

3. Remove characters from the first string which are present in the second string

void removeCharacters(char* str, char* mask)
{
	int count[256];
	memset(count, 0, sizeof(count));

	for(int i = 0; mask[i]; i++)
		count[mask[i]]++;

	int res_ind = 0;
	for(int ip_ind = 0; str[ip_ind]; ip_ind++)
	{
		if(count[str[ip_ind]] == 0)
			str[res_ind++] = str[ip_ind];
	}

	str[res_ind] = '\0';
}

Time complexity = O(m + n), where m and n are the lengths of str and mask

4. Given an array A[] and a number x, check for pair in A[] with sum as x

bool pairSum(int a[], int n, int sum)
{
	unordered_set<int> hash;

	for(int i = 0; i < n; i++)
	{
		if(hash.find(sum - a[i]) != hash.end())
		{
			printf("%d %d", a[i], sum - a[i]);
			return true;
		}
		else
			hash.insert(a[i]);
	}

	return false;
}

Time complexity = O(n)
Space complexity = O(n)

5. Majority element

int findCandidate(int a[], int n)
{
	int count = 1;
	int maj_index = 0;

	for(int i = 1; i < n; i++)
	{
		if(a[i] == a[maj_index])
			count++;
		else
			count--;

		if(count == 0)
		{
			count = 1;
			maj_index = i;
		}
	}

	return a[maj_index];
}

int majorityElement(int a[], int n)
{
	int cand = findCandidate(a, n);
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(a[i] == cand)
			count++;
	}

	if(count > n / 2)
		return cand;
	else
		return -1;
}

Time complexity = O(n)

6. Write an Efficient Method to Check if a Number is Multiple of 3

bool isMultipleof3(int n)
{
	if(n < 0)
		n = -n;
	if(n == 0)
		return true;
	if(n == 1)
		return false;

	int odd_count = 0, even_count = 0;

	while(n != 0)
	{
		if(n & 1)
			odd_count++;
		n >>= 1;

		if(n & 1)
			even_count++;
		n >>= 1;
	}

	return isMultipleof3(abs(odd_count - even_count));
}

Time complexity = O(log n)

7. Position of rightmost set bit

int posRtMostBit(int n)
{
	return log2(n & ~(n - 1)) + 1;
}

Time complexity = O(1)

8. Find the Number Occurring Odd Number of Times

int oddOccurence(int a[], int n)
{
	int result = 0;

	for(int i = 0; i < n; i++)
		result ^= a[i];

	return result;
}

Time complexity = O(n)

9. Largest Sum Contiguous Subarray

int kadane(int a[], int n)
{
	int max_so_far = a[0];
	int curr_sum = a[0];

	for(int i = 1; i < n; i++)
	{
		curr_sum = max(curr_sum + a[i], a[i]);
		max_so_far = max(max_so_far, curr_sum);
	}

	return max_so_far;
}

Time complexity = O(n)

10. Find the Missing Number (Given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list)

int missing_number(int a[], int n)
{
	int total = (n + 1) * (n + 2) / 2;

	for(int i = 0; i < n; i++)
		total -= a[i];

	return total;
}

Time complexity = O(n)

11. Write Code to Determine if Two Trees are Identical

bool isIdentical(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;
	return a->data == b->data && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
}

Time complexity = O(min(m, n)), where m and n are the number of nodes in tree1 and tree2 respectively

12. Write a Program to Find the Maximum Depth or Height of a Tree

int height(struct node* root)
{
	if(root == NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

Time complexity = O(n) where n is the number of nodes in the tree

13. Convert a Binary Tree into its Mirror Tree / Invert the signs and get a new BST

void convert(struct node* root)
{
	if(root == NULL)
		return;

	convert(root->left);
	convert(root->right);

	struct node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

Time complexity = O(n) where n is the number of nodes in the tree

14. Find the middle of a given linked list

int midList(struct node* head)
{
	if(head == NULL)
		return -1;

	struct node* slowptr = head;
	struct node* fastptr = head;

	while(fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	return slowptr->data;
}

Time complexity = O(n) where n is the length of the linked list

15. Program for n’th node from the end of a Linked List 

int printnthfromend(struct node* head, int n)
{
	if(head == NULL)
		return -1;

	struct node* slowptr = head;
	struct node* fastptr = head;

	for(int i = 1; i <= n - 1 && fastptr != NULL; i++)
		fastptr = fastptr->next;

	while(fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}

	return slowptr->data;
}

Time complexity = O(n) where n is the length of the linked list

16. Write a program to print all permutations of a given string

void permutations(char* str, int begin, int end)
{
	if(begin == end)
		printf("%s", str)
	else
	{
		for(int i = begin; i <= end; i++)
		{
			swap(&str[begin], &str[i]);
			permutations(str, begin + 1, end);
			swap(&str[begin], &str[i]);
		}
	}
}

Time complexity = O(n*n!) Note that there are n! permutations and it requires O(n) time to print a a permutation.

17. Write an Efficient C Program to Reverse Bits of a Number

unsigned int swapPosBits(unsigned int num, int p1, int p2)
{
	int p1_bit = (num >> p1) & 1;
	int p2_bit = (num >> p2) & 1;

	if(p1_bit ^ p2_bit)
	{
		num ^= 1 << p1;
		num ^= 1 << p2;
	}

	return num;
}

unsigned int reverseBits(unsigned int num)
{
	int MAX_BITS = sizeof(num) * 8;
	for(int i = 0; i < MAX_BITS / 2; i++)
		num = swapPosBits(num, i, MAX_BITS - 1 - i);
	return num;
}

18. Reverse a linked list

void reverseList(struct node** head)
{
	struct node* rider = *head;
	struct node* r_next = NULL;
	struct node* prev = NULL;

	while(rider != NULL)
	{
		r_next = rider->next;
		rider->next = prev;
		prev = rider;
		rider = r_next;
	}

	*head = prev;
}

Time complexity = O(n) where n is the length of the linked list

19. Detect loop in a linked list and return the first node of the loop

/*
Distance travelled by fastptr = 2 * Distance travelled by slowptr
m + xn + k = 2 * (m + yn + k)
m + k = xn - 2yn
m + k = n * (x - 2y)
*/

struct node* detectLoop(struct node* head)
{
	if(head == NULL || head->next == NULL)
		return NULL;

	struct node* slowptr = head;
	struct node* fastptr = head;

	while(slowptr != NULL && fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;

		if(slowptr == fastptr)
			break;
	}

	if(slowptr == fastptr)
	{
		slowptr = head;
		while(slowptr != fastptr)
		{
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}

		return fastptr;
	}

	return NULL;
}

Time complexity = O(n) where n is the length of the linked list

20. Lowest Common Ancestor in a Binary Search Tree

struct node* LCA(struct node* root, int k1, int k2)
{
	while(root != NULL)
	{
		if(k1 < root->data && k2 < root->data)
			root = root->left;
		else if(k1 > root->data && k2 > root->data)
			root = root->right;
		else
			break;
	}

	return root;
}

Time complexity : O(h), where h is height of the tree

21. Function to check if a singly linked list is palindrome

bool isIdentical(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;
	return a->data == b->data && isIdentical(a->next, b->next);
}

bool isPalindrome(struct node* head)
{
	if(head == NULL)
		return false;
	if(head->next == NULL)
		return true;

	struct node* slowptr = head;
	struct node* fastptr = head;
	struct node* prev = NULL;

	while(fastptr != NULL && fastptr->next != NULL)
	{
		prev = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	struct node* mid = NULL;
	if(fastptr != NULL)
	{
		mid = slowptr;
		slowptr = slowptr->next;
	}

	struct node* a = head;
	struct node* b = slowptr;
	prev->next = NULL;

	reverseList(&b);
	bool result = isIdentical(a, b);
	reverseList(&b);

	if(mid != NULL)
	{
		prev->next = mid;
		mid->next = b;
	}
	else
		prev->next = b;

	return result;
}

Time complexity = O(n) where n is the length of the linked list

22. Search an element in a sorted and rotated array

int binSearch(int a[], int low, int high, int key)
{
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

int findPivot(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(mid < high && a[mid] > a[mid + 1])
			return mid + 1;
		if(mid > low && a[mid - 1] > a[mid])
			return mid;

		if(a[low] <= a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0;
}

int searchRotated(int a[], int n, int key)
{
	int pivot = findPivot(a, n);

	if(pivot != 0 && key >= a[0] && key <= a[pivot - 1])
		return binSearch(a, 0, pivot - 1, key);
	else
		return binSearch(a, pivot, n - 1, key);
}

Time complexity = O(log n)

23. Clone a linked list with next and random pointer

struct node* clone(struct node* org_start)
{
	struct node* orider = org_start;
	while(orider != NULL)
	{
		struct node* or_next = orider->next;
		orider->next = newNode(orider->data);
		orider->next->next = or_next;
		orider = or_next;
	}

	orider = org_start;
	while(orider != NULL)
	{
		orider->next->random = orider->random->next;
		orider = orider->next ? orider->next->next : orider->next;
	}

	orider = org_start;
	struct node* copy_start = org_start->next;
	struct node* crider = copy_start;

	while(orider != NULL && crider != NULL)
	{
		orider->next = orider->next ? orider->next->next : orider->next;
		crider->next = crider->next ? crider->next->next : crider->next;
		orider = orider->next;
		crider = crider->next; 
	}

	return copy_start;
}

Time complexity = O(n)

24. Merge an array of size n into another array of size m+n

void moveToEnd(int MplusN[], int size)
{
	int j = 0;
	for(int i = 0; i < size; i++)
	{
		if(MplusN[i] != NA)
			MplusN[j++] = MplusN[i];
	}

	while(j < size)
		MplusN[j++] = NA;
}

void merge(int MplusN[], int N[], int m, int n)
{
	int i = m - 1, j = n - 1, k = m + n - 1;

	while(j >= 0)
	{
		if(i >= 0 && MplusN[i] >= N[j])
			MplusN[k--] = MplusN[i--];
		else
			MplusN[k--] = N[j--];
	}
}

Time complexity = O(m + n)

25. Count number of bits to be flipped to convert A to B

int countSetBits(int n)
{
	int count = 0;
	while(n != 0)
	{
		count++;
		n = n & (n - 1);
	}

	return count;
}

int countFlipBits(int a, int b)
{
	return countSetBits(a ^ b);
}

26. Given a string, find its first non-repeating character

char getFirstNonRepeating(char* str)
{
	int count[256] = {0};

	for(int i = 0; str[i]; i++)
		count[str[i]]++;

	for(int i = 0; str[i]; i++)
	{
		if(count[str[i]] == 1)
			return str[i];
	}

	return -1;
} 

27. Given a linked list which is sorted, how will you insert in sorted way

void sorted_insert(struct node** head, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;

	struct node* rider = *head;

	if(rider == NULL || temp->data <= rider->data)
	{
		temp->next = rider;
		*head = temp;
	}
	else
	{
		while(rider->next != NULL && temp->data > rider->next->data)
			rider = rider->next;
		temp->next = rider->next;
		rider->next = temp;
	}
}

28. Median of two sorted arrays of same size

int getMedian(int a[], int n)
{
	if(n % 2 == 0)
		return (a[n/2] + a[n/2 - 1]) / 2;
	else
		return a[n/2];
}

int median(int a1[], int a2[], int n)
{
	if(n == 1)
		return (a1[0] + a2[0]) / 2;		
	if(n == 2)
		return (max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2;

	int m1 = getMedian(a1, n);
	int m2 = getMedian(a2, n);

	if(m1 == m2)
		return m1;
	else if(m1 < m2)
	{
		if(n % 2 == 0)
			return median(a1 + n/2 - 1, a2, n - n/2 + 1);
		else
			return median(a1 + n/2, a2, n - n/2);	
	}
	else
	{
		if(n % 2 == 0)
			return median(a2 + n/2 - 1, a1, n - n/2 + 1);
		else
			return median(a2 + n/2, a1, n - n/2);
	}
}

Time complexity = O(log n)

29. Write a function to get the intersection point of two Linked Lists

int count(struct node* head)
{
	int c = 0;
	while(head != NULL)
	{
		c++;
		head = head->next;
	}

	return c;
}

struct node* getIntersectionUtil(struct node* a, struct node* b, int d)
{
	for(int i = 1; i <= d; i++)
		a = a->next;

	while(a != NULL && b != NULL && a != b)
	{
		a = a->next;
		b = b->next;
	}

	return a;
}

struct node* getIntersection(struct node* a, struct node* b)
{
	int c1 = count(a);
	int c2 = count(b);

	if(c1 > c2)
		return getIntersectionUtil(a, b, c1 - c2);
	else
		return getIntersectionUtil(b, a, c2 - c1);
}

Time complexity = O(m + n)

30. Find the two non-repeating elements in an array of repeating elements / Find the two numbers with odd occurrences in an unsorted array

void getNonRepeating(int a[], int n, int* x, int* y)
{
	*x = 0, *y = 0;
	int Xor = 0;

	for(int i = 0; i < n; i++)
		Xor ^= a[i];

	int set_bit_no = Xor & ~(Xor - 1);

	for(int i = 0; i < n; i++)
	{
		if(a[i] & set_bit_no)
			*x ^= a[i];
		else
			*y ^= a[i];
	}
}

31. Write a program to reverse an array or string

void reverseArray(int a[], int start, int end)
{
	while(start < end)
	{
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

32. Level Order Traversal

void levelOrder(struct node* root)
{
	if(root == NULL)
		return;

	queue<struct node*> q;
	q.push(root);

	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();

		printf("%d", temp->data);

		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

Time complexity = O(n), where is the number of nodes in the tree
Space complexity = O(n)

33. Program for array rotation

void leftRotate(int a[], int n, int d)
{
	int mod = d % n;
	reverseArray(a, 0, mod - 1);
	reverseArray(a, mod, n - 1);
	reverseArray(a, 0, n - 1);
}

void rightRotate(int a[], int n, int d)
{
	int mod = d % n;
	reverseArray(a, 0, n - 1);
	reverseArray(a, 0, mod - 1);
	reverseArray(a, mod, n - 1);
}

34. A program to check if a binary tree is BST or not 

bool isBST(struct node* root, int min, int max)
{
	if(root == NULL)
		return true;
	if(root->data < min || root->data > max)
		return false;
	return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

Time complexity = O(n)

35. Maximum sum such that no two elements are adjacent

int maxSumNotAdj(int a[], int n)
{
	int DP[n];
	DP[0] = a[0];
	DP[1] = max(a[0], a[1]);

	for(int i = 2; i < n; i++)
		DP[i] = max(DP[i - 2] + a[i], DP[i - 1]);

	return DP[n - 1]; 
}

Time complexity = O(n)
Space complexity = O(n)

36. Leaders in an array

void printLeaders(int a[], int n)
{
	int max_from_right = a[n - 1];
	printf("%d", max_from_right);

	for(int i = n - 2; i >= 0; i--)
	{
		if(a[i] > max_from_right)
		{
			max_from_right = a[i];
			printf("%d", max_from_right);
		}
	}
}

Time complexity = O(n)

37. Level order traversal in spiral form

void levelOrderSpiral(struct node* root)
{
	if(root == NULL)
		return;

	deque<struct node*> q;
	q.push_back(root);
	bool leftToRight = true;

	while(1)
	{
		int n = q.size();

		if(n == 0)
			break;

		if(leftToRight)
		{
			for(int i = 1; i <= n; i++)
			{
				struct node* temp = q.front();
				q.pop_front();

				printf("%d", temp->data);

				if(temp->left)
					q.push_back(temp->left);
				if(temp->right)
					q.push_back(temp->right);
			}
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				struct node* temp = q.back();
				q.pop_back();

				printf("%d", temp->data);

				if(temp->right)
					q.push_front(temp->right);
				if(temp->left)
					q.push_front(temp->left);
			}
		}

		leftToRight = !leftToRight;
		printf("\n");
	}
}

Time complexity = O(n), where n is the number of nodes in the tree
Space complexity = O(n)

38. Sort elements by frequency

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second > p2.second;
}

void sortByFrequency(int a[], int n)
{
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++)
		hash[a[i]]++;

	int size = hash.size();
	pair<int, int> p[size];
	
	int index = 0;
	for(auto it = hash.begin(); it != hash.end(); it++)
		p[index++] = make_pair(it->first, it->second);

	sort(p, p + size, compare);

	for(int i = 0; i < size; i++)
	{
		while(p[i].second--)
			printf("%d", p[i].first);
	}
}

Time complexity = O(n + m log m) where n is total number of elements and m is total number of distinct elements

39. Count Inversions in an array

int merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	int i, j, k;
	int count = 0;

	for(i = 0; i < n1; i++)
		L[i] = a[l + i];

	for(j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	i = 0, j = 0, k = l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
			a[k++] = L[i++];
		else
		{
			count += n1 - i;
			a[k++] = R[j++];
		}
	}

	while(i < n1)
		a[k++] = L[i++];
	while(j < n2)
		a[k++] = R[j++];

	return count;
}

int merge_sort(int a[], int l, int r)
{
	int count = 0;
	while(l < r)
	{
		int m = l + (r - l) / 2;
		count += merge_sort(a, l, m);
		count += merge_sort(a, m + 1, r);
		count += merge(a, l, m, r);
	}

	return count;
}

Time complexity = O(n log n)

40. Two elements whose sum is closest to zero

void sumClosest(int a[], int n)
{
	sort(a, a + n);
	int l = 0, r = n - 1;
	int min_sum = INT_MAX, min_l, min_r;

	while(l < r)
	{
		int sum = a[l] + a[r];
		if(abs(sum) < min_sum)
		{
			min_sum = abs(sum);
			min_l = l;
			min_r = r;
		}

		if(sum < 0)
			l++;
		else
			r--;
	}

	printf("%d %d", min_l, min_r);
}
Time complexity = O(n log n)

41. Find the smallest and second smallest elements in an array

void printSmall(int a[], int n)
{
	int first_min = INT_MAX, sec_min = INT_MAX;

	for(int i = 0; i < n; i++)
	{
		if(a[i] < first_min)
		{
			sec_min = first_min;
			first_min = a[i];
		}
		else if(a[i] < sec_min && a[i] != first_min)
			sec_min = a[i];
	}

	printf("%d %d", first_min, sec_min);
}

42. Check for Children Sum Property in a Binary Tree

bool isChildrenSum(struct node* root)
{
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return true;

	return root->data == (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0) && isChildrenSum(root->left) && isChildrenSum(root->right);
}

Time complexity = O(n) where n is the number of nodes in the tree

43. Remove duplicates from an unsorted linked list

void removeDupUnsorted(struct node* head)
{
	unordered_set<int> hash;
	struct node* prev = NULL;

	while(head != NULL)
	{
		if(hash.find(head->data) == hash.end())
		{
			hash.insert(head->data);
			prev = head;
		}
		else
		{
			prev->next = head->next;
			free(head);
		}

		head = prev->next;
	}
}

44. Segregate 0s and 1s in an array

void segregate01(int a[], int n)
{
	int i = -1;
	for(int j = 0; j < n; j++)
	{
		if(a[j] == 0)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
}

45. K’th Smallest/Largest Element in Unsorted Array | Set 1

int partition(int a[], int low, int high)
{
	int i = low - 1;
	int pivot = a[high];

	for(int j = low; j <= high - 1; j++)
	{
		if(a[j] <= pivot) // > kth largest
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	i++;
	swap(&a[i], &a[high]);
	return i;
}

int randomPartition(int a[], int low, int high)
{
	int n = high - low + 1;
	srand(time(NULL));
	int pivot = rand() % n;
	swap(&a[low + pivot], &a[high]);
	return partition(a, low, high);
}

int quick_select(int a[], int low, int high, int k)
{
	if(low == high && low == k - 1)
		return a[low];

	if(low < high)
	{
		int p = randomPartition(a, low, high);
		if(k - 1 == p)
			return a[p];
		else if(k - 1 < p)
			return quick_select(a, low, p - 1, k);
		else
			return quick_select(a, p + 1, high, k); 
	}
}

Time complexity = O(n) -> average, O(n^2) -> worst

46. Queue using Stacks

class Queue
{
	stack<int> s;
public:
	void enqueue(int element)
	{
		s.push(element);
	}

	int dequeue()
	{
		if(s.empty())
			return -1;

		int element = s.top();
		s.pop();

		if(s.empty())
			return element;

		int result = dequeue();

		s.push(element);

		return result;
	}
};

47. Diameter of a Binary Tree

int height(struct node* root, int* d)
{
	if(root == NULL)
		return 0;

	int lh = height(root->left, d);
	int rh = height(root->right, d);

	*d = max(*d, lh + rh + 1);

	return 1 + max(lh, rh);
}

Time complexity = O(n)

48. How to determine if a binary tree is height-balanced?

int height(struct node* root)
{
	if(root == NULL)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	if(lh == -1 || rh == -1)
		return -1;
	if(abs(lh - rh) > 1)
		return -1;

	return 1 + max(lh, rh);
}

Time complexity = O(n)

49. Maximum size square sub-matrix with all 1s

void maxSquare1(int M[][], int m, int n)
{
	int DP[m][n];

	for(int j = 0; j < n; j++)
		DP[0][j] = M[0][j];

	for(int i = 0; i < m; i++)
		DP[i][0] = M[i][0];

	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(M[i][j] == 0)
				DP[i][j] = 0;
			else
				DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
		}
	}

	int max_square = INT_MIN, max_i, max_j;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(DP[i][j] > max_square)
			{
				max_square = DP[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	for(int i = max_i - max_square + 1; i <= max_i; i++)
	{
		for(int j = max_j - max_square + 1; j <= max_j; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}

}

Time complexity = O(m * n)
Space complexity = O(m * n)

50. Root to leaf path sum equal to a given number

bool isRootLeafPath(struct node* root, int sum, int k)
{
	if(root == NULL)
		return false;

	sum += root->data;

	if(root->left == NULL && root->right == NULL)
		return (sum == k);

	return isRootLeafPath(root->left, sum, k) || isRootLeafPath(root->right, sum, k);
}

Time complexity = O(n)

51. Maximum difference between two elements such that larger element appears after the smaller number

int maxDiff(int a[], int n)
{
	int max_diff = INT_MIN;
	int min_element = INT_MAX;

	for(int i = 0; i < n; i++)
	{
		if(a[i] < min_element)
			min_element = a[i];
		if(a[i] - min_element > max_diff)
			max_diff = a[i] - min_element;
	}

	return max_diff;
}

Time complexity = O(n)

52. Check for balanced parantheses in an expression

bool isMatchingPair(char open, char close)
{
	return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool isBalanced(char* exp)
{
	stack<char> s;

	for(int i = 0; exp[i]; i++)
	{
		if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
			s.push(exp[i]);
		else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if(s.empty())
				return false;
			if(!isMatchingPair(s.top(), exp[i]))
				return false;

			s.pop();
		}
	}

	return s.empty();
}

Time complexity = O(n)
Space complexity = O(n)

53. Construct Tree from given Inorder and Preorder traversals

struct node* construct(int in[], int pre[], int inS, int inE, int preS, int preE)
{
	if(inS > inE)
		return NULL;

	int rootData = pre[preS];
	int rootIndex = -1;
	for(int i = inS; i <= inE; i++)
	{
		if(in[i] == rootData)
		{
			rootIndex = i;
			break;
		}
	}

	int lInS = inS; 
	int lInE = rootIndex - 1;
	int rInS = rootIndex + 1;
	int rInE = inE;

	int lPreS = preS + 1;
	int lPreE = lPreS + lInE - lInS;
	int rPreS = lPreE + 1;
	int rPreE = preE;

	struct node* root = newNode(rootData);
	root->left = construct(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = construct(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

Time complexity = O(n)

54. Given a binary tree, print all root-to-leaf paths

void printRootLeafPaths(struct node* root, int path[], int index)
{
	if(root == NULL)
		return;

	path[index++] = root->data;

	if(root->left == NULL && root->right == NULL)
	{
		for(int i = 0; i < index; i++)
			printf("%d", path[i]);
		return;
	}

	printRootLeafPaths(root->left, path, index);
	printRootLeafPaths(root->right, path, index);
}

55. Pairwise swap elements of a given linked list 

void pairwiseSwap(struct node* head)
{
	while(head != NULL && head->next != NULL)
	{
		swap(&head->data, &head->next->data);
		head = head->next->next;
	}
}

56. Reverse words in a given string

void reverseArray(char* str, int start, int end)
{
	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void reverseWords(char* str)
{
	int word_begin = 0;
	int len = strlen(str);

	for(int i = 0; i < len; i++)
	{
		if(str[i] == ' ')
		{
			reverseArray(str, word_begin, i - 1);
			word_begin = i + 1;
		}
	}

	reverseArray(str, word_begin, len - 1);
	reverseArray(str, 0, len - 1);
}

57. Delete a node in a Doubly Linked List

void delNode(struct node** head, struct node* ptr)
{
	if(*head == NULL || ptr == NULL)
		return;

	if(*head == ptr)
		*head = (*head)->next;

	if(ptr->next != NULL)
		ptr->next->prev = ptr->prev;
	if(ptr->prev != NULL)
		ptr->prev->next = ptr->next;

	free(ptr);
}

58. Run Length Encoding

string RLE(string src)
{
	int len = src.length();
	string dest = "";

	for(int i = 0; i < len; i++)
	{
		dest += src[i];

		int rlen = 1;
		while(i + 1 < len && src[i] == src[i + 1])
		{
			rlen++;
			i++;
		}

		dest += to_string(rlen);
	}

	return dest;
}

59. Maximum width of a binary tree

int maxWidth(struct node* root)
{
	if(root == NULL)
		return 0;

	queue<struct node*> q;
	q.push(root);
	int max_width = INT_MIN;

	while(1)
	{
		int n = q.size();

		max_width = max(max_width, n);

		if(n == 0)
			break;

		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}

	return max_width;
}

60. Intersection of two Sorted Linked Lists

struct node* intersectSortedLists(struct node* a, struct node* b)
{
	if(a == NULL || b == NULL)
		return NULL;

	if(a->data < b->data)
		return intersectSortedLists(a->next, b);
	else if(a->data > b->data)
		return intersectSortedLists(a, b->next);
	else
	{
		struct node* result = newNode(a->data);
		result->next = intersectSortedLists(a->next, b->next);
		return result;
	}
}

Time complexity = O(m + n)

61. Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i].

void productArray(int a[], int n)
{
	int prod[n];

	int temp = 1;
	for(int i = 0; i < n; i++)
	{
		prod[i] = temp;
		temp *= a[i];
	}

	temp = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		prod[i] *= temp;
		temp *= a[i];
	}

	for(int i = 0; i < n; i++)
		printf("%d", prod[i]);
}

62. Total number of possible Binary Search Trees and Binary Trees with n keys

/*
BST = Catalan number
	= 2nCn / (n + 1)
	= (2n)!/(n+1)!n!

BT = (2n)!/(n+1)!
*/

int factorial(int n)
{
	int result = 1;

	for(int i = 1; i <= n; i++)
		result *= i;

	return result;
}

void total_BST_BT(int n)
{
	int a = factorial(2 * n);
	int b = factorial(n + 1);
	int c = factorial(n);

	printf("BST : %d", a / (b * c));
	printf("BT : %d", a / b);
}

63. Merge two sorted linked lists 

struct node* mergeSortedLists(struct node* a, struct node* b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;

	if(a->data <= b->data)
	{
		a->next = mergeSortedLists(a->next, b);
		return a;
	}
	else 
	{
		b->next = mergeSortedLists(a, b->next);
		return b; 
	}
}

64. Reverse a Linked List in groups of given size

struct node* reverseListK(struct node* head, int k)
{
	struct node* prev = NULL;
	struct node* rider = head;
	struct node* r_next = NULL;
	int count = 0;

	while(rider != NULL && count < k)
	{
		r_next = rider->next;
		rider->next = prev;
		prev = rider;
		rider = r_next;
		count++;
	}

	if(rider != NULL)
		head->next = reverseListK(rider, k);

	return prev;
}

65. Sort an array of 0s, 1s and 2s

void sort012(int a[], int n)
{
	int low = 0, mid = 0, high = n - 1;

	while(mid <= high)
	{
		switch(a[mid])
		{
			case 0 : swap(&a[low++], &a[mid++]);
					 break;
			case 1 : mid++;
					 break;
			case 2 : swap(&a[mid], &a[high--]);
					 break;
		}
	} 
}

66. Print nodes at k distance from root

void printDistanceK(struct node* root, int level)
{
	if(root == NULL)
		return;

	if(level == 0)
	{
		printf("%d", root->data);
		return;
	}

	printDistanceK(root->left, level - 1);
	printDistanceK(root->right, level - 1);
}

Time complexity = O(n), where is the number of nodes in the tree

67. Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times. Find these repeating numbers in O(n) and using only constant memory space.

void duplicates(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int index = a[i] % n;
		a[index] += n;
	}

	for(int i = 0; i < n; i++)
	{
		if(a[i] / n > 1)
			printf("%d", i);
	}
}

68. Equilibrium index of an array 

int equilibrium(int a[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];

	int leftsum = 0;
	for(int i = 0; i < n; i++)
	{
		sum -= a[i]
		if(leftsum == sum)
			return i;
		leftsum += a[i];
	}

	return -1;
}

69. Inorder predecessor and successor for a given key in BST

struct node* findMin(struct node* root)
{
	while(root->left != NULL)
		root = root->left;
	return root;
}

struct node* findMax(struct node* root)
{
	while(root->right != NULL)
		root = root->right;
	return root;
}

void inorderSuccPre(struct node* root, int k, struct node* succ, struct node* pre)
{
	while(root != NULL)
	{
		if(k < root->data)
		{
			*succ = root;
			root = root->left;
		}
		else if(k > root->data)
		{
			*pre = root;
			root = root->right;
		}
		else
		{
			*succ = findMin(root->right);
			*pre = findMax(root->left);
			break;
		}
	}
}

70. Find k-th smallest element in BST

int kthsmallest(struct node* root, int k)
{
	struct node* current = root;
	int count = 0;
	int ksmall;

	while(current != NULL)
	{
		if(current->left == NULL)
		{
			count++;
			if(count == k)
				ksmall = current->data;
			current = current->right;
		}
		else
		{
			struct node* pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;

			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else if(pre->right != NULL)
			{
				pre->right = NULL;

				count++;
				if(count == k)
					ksmall = current->data;

				current = current->right;
			}
		}
	}

	return ksmall;
}

Time complexity = O(n)

71. Sorted insert for circular linked list

void sorted_insert(struct node** head, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;

	struct node* rider = *head;

	if(rider == NULL)
	{
		*head = temp;
		(*head)->next = *head;
	}
	else if(temp->data <= rider->data)
	{
		while(rider->next != *head)
			rider = rider->next;
		rider->next = temp;
		temp->next = *head;
		*head = temp;
	}
	else
	{
		while(rider->next != *head && temp->data > rider->next->data)
			rider = rider->next;
		temp->next = rider->next;
		rider->next = temp;
	}
}

72. Program for Fibonacci numbers

int fibonacci(int n)
{
	int DP[n + 1];
	DP[0] = 0;
	DP[1] = 1;

	for(int i = 2; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	return DP[n];
}

73. Find the smallest window in a string containing all characters of another string

void minWindowSubstring(char* S, char* T)
{
	int needToFind[256];
	memset(needToFind, 0, sizeof(needToFind));

	int hasFound[256];
	memset(hasFound, 0, sizeof(hasFound));

	int tLen = strlen(T);
	for(int i = 0; T[i]; i++)
		needToFind[T[i]]++;

	int min_window = INT_MAX, min_begin, min_end;
	int count = 0;
	int begin = 0;
	for(int end = 0; S[end]; end++)
	{
		if(needToFind[S[end]] == 0)
			continue;

		hasFound[S[end]]++;

		if(hasFound[S[end]] <= needToFind[S[end]])
			count++;

		if(count == tLen)
		{
			while(needToFind[S[begin]] == 0 || hasFound[S[begin]] > needToFind[S[begin]])
			{
				if(hasFound[S[begin]] > needToFind[S[begin]])
					hasFound[S[begin]]--;
				begin++;
			}

			int window = end - begin + 1;
			if(window < min_window)
			{
				min_window = window;
				min_begin = begin;
				min_end = end;
			}
		}
	}

	for(int i = min_begin; i <= min_end; i++)
		printf("%c", S[i]);
}

74. Search in a row wise and column wise sorted matrix

bool searchMatrixSorted(int M[][], int m, int n, int key)
{
	int i = 0, j = n - 1;
	while(i < m && j >= 0)
	{
		if(key == M[i][j])
		{
			printf("%d %d", i, j);
			return true;
		}
		else if(key < M[i][j])
			j--;
		else
			i++;
	}

	return false;
}

Time complexity = O(m + n)

75. Next Greater Element

void NGE(int a[], int n)
{
	stack<int> s;

	for(int i = 0; i < n; i++)
	{
		while(!s.empty() && a[i] > s.top())
		{
			printf("%d %d", s.top(), a[i]);
			s.pop();
		}

		s.push(a[i]);
	}

	while(!s.empty())
	{
		printf("%d -1", s.top());
		s.pop();
	}
}

76. KMP Algorithm for Pattern Searching

void computeLPS(char* pat, int m, int LPS[])
{
	LPS[0] = 0;

	int i = 1;
	int index = 0;

	while(i < m)
	{
		if(pat[i] == pat[index])
		{
			LPS[i] = index + 1;
			i++;
			index++;
		}
		else
		{
			if(index == 0)
			{
				LPS[i] = 0;
				i++;
			}
			else
				index = LPS[index - 1];
		}
	}
}

bool KMPMatch(char* text, char* pat)
{
	int n = strlen(text);
	int m = strlen(pat);

	int LPS[m];
	computeLPS(pat, m, LPS);

	int i = 0, j = 0;
	while(i < n)
	{
		if(text[i] == pat[j])
		{
			i++;
			j++;

			if(j == m)
			{
				printf("Found at %d", i - j);
				return true;
			}
		}
		else
		{
			if(j == 0)
				i++;
			else
				j = LPS[j - 1];
		}
	}

	return false;
}

Time complexity = O(n)

77. Segregate even and odd nodes in a Linked List

void segregateEvenOdd(struct node** head)
{
	struct node* rider = *head;
	struct node* evenStart = NULL;
	struct node* evenEnd = NULL;
	struct node* oddStart = NULL;
	struct node* oddEnd = NULL;

	while(rider != NULL)
	{
		if(rider->data % 2 == 0)
		{
			if(evenStart == NULL)
			{
				evenStart = rider;
				evenEnd = rider;
			}
			else
			{
				evenEnd->next = rider;
				evenEnd = evenEnd->next;
			}
		}
		else
		{
			if(oddStart == NULL)
			{
				oddStart = rider;
				oddEnd = rider;
			}
			else
			{
				oddEnd->next = rider;
				oddEnd = oddEnd->next;
			}
		}

		rider = rider->next;
	}

	if(evenStart == NULL || oddStart == NULL)
		return;

	*head = evenStart;
	evenEnd->next = oddStart;
	oddEnd->next = NULL;
}

78. Count number of occurrences (or frequency) in a sorted array

int firstOcc(int a[], int n, int key)
{
	int first = -1;
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
		{
			first = mid;
			high = mid - 1;
		}
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}	

	return first;
}

int lastOcc(int a[], int n, int key)
{
	int last = -1;
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
		{
			last = mid;
			low = mid + 1;
		}
		else if(key < a[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}

	return last;
}

int frequency(int a[], int n, int key)
{
	int first = firstOcc(a, n, key);
	if(first == -1)
		return 0;
	int last = lastOcc(a, n, key);
	return last - first + 1;
}

79. Check if a given Binary Tree is SumTree

int isSumTree(struct node* root, int* result)
{
	if(root == NULL || (root->left == NULL && root->right == NULL))
	{
		*result = 1;
		return root ? root->data : 0;
	}

	int ls = isSumTree(root->left, result);
	int rs = isSumTree(root->>right, result);

	if(ls + rs == root->data)
	{
		*result = 1;
		return 2 * root->data;
	}
	else
	{
		*result = 0;
		return root->data + ls + rs;
	}

}

Time complexity = O(n)

80. Given an array arr[], find the maximum j – i such that arr[j] > arr[i]

int maxIndexDiff(int a[], int n)
{
	int LMin[n];
	LMin[0] = a[0];
	for(int i = 1; i < n; i++)
		LMin[i] = min(LMin[i - 1], a[i]);

	int RMax[n];
	RMax[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--)
		RMax[i] = max(RMax[i + 1], a[i]);

	int max_diff = INT_MIN;
	int i = 0, j = 0;
	while(i < n && j < n)
	{
		if(LMin[i] < RMax[j])
		{
			max_diff = max(max_diff, j - i);
			j++;
		}
		else
			i++;
	}

	return max_diff;
}

Time complexity = O(n)
Space complexity = O(n)

81. Maximum of all subarrays of size k

void maxSubarrayK(int a[], int n, int k)
{
	deque<int> q;

	int end;
	for(end = 0; end < k; end++)
	{
		while(!q.empty() && a[end] >= a[q.back()])
			q.pop_back();
		q.push_back(end);
	}

	int begin = 0;
	for(; end < n; end++)
	{
		printf("%d", a[q.front()]);

		if(q.front() == begin)
			q.pop_front();

		while(!q.empty() && a[end] >= a[q.back()])
			q.pop_back();
		q.push_back(end);

		begin++;
	}

	printf("%d", a[q.front()]);
}

Time complexity = O(n)
Space complexity = O(k)

82. Longest Increasing Subsequence

int LIS(vector<int> a) 
{
    int n = a.size();
    int max_lis = 0;

    vector<int> DP(n, INT_MAX);
	
	for(int i = 0; i < n; i++) 
	{
	    auto it = lower_bound(DP.begin(), DP.end(), a[i]);
		*it = a[i];
        max_lis = max(max_lis, it - DP.begin() + 1);
	}

    return max_lis;
}

Time complexity = O(n log n)
Space complexity = O(n)

83. Longest Common Subsequence

int LCS(char* X, char* Y)
{
	int m = strlen(X);
	int n = strlen(Y);

	int DP[m + 1][n + 1];

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
				DP[i][j] = 0;
			else if(X[i - 1] == Y[j - 1])
				DP[i][j] = 1 + DP[i - 1][j - 1];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	return DP[m][n];
}

84. Edit Distance

int editDistance(char* X, char* Y)
{
	int m = strlen(X);
	int n = strlen(Y);

	int DP[m + 1][n + 1];

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0)
				DP[i][j] = j;
			else if(j == 0)
				DP[i][j] = i;
			else if(X[i - 1] == Y[j - 1])
				DP[i][j] = DP[i - 1][j - 1];
			else
				DP[i][j] = 1 + min(DP[i][j - 1], DP[i - 1][j - 1], DP[i - 1][j]);
		}
	}

	return DP[m][n];
}

//TODO : learn the complexity
85. Check if a binary tree is subtree of another binary tree

bool isSubtree(struct node* a, struct node* b)
{
	if(a == NULL)
		return false;
	if(b == NULL)
		return true;

	if(isIdentical(a, b))
		return true;
	else
		return isSubtree(a->left, b) || isSubtree(a->right, b);
}

Time complexity = O(m * n), where m and n are the number of nodes in a and b

86. Find the repeating and the missing (Array elements are in the range from 1 to n)

void getRepeatingMissing(int a[], int n, int* x, int* y)
{
	*x = 0, *y = 0;
	int Xor = 0;

	for(int i = 0; i < n; i++)
		Xor ^= a[i];

	for(int i = 1; i <= n; i++)
		Xor ^= i;

	int set_bit_no = Xor & ~(Xor - 1);

	for(int i = 0; i < n; i++)
	{
		if(a[i] & set_bit_no)
			*x ^= a[i];
		else
			*y ^= a[i];
	}

	for(int i = 1; i <= n; i++)
	{
		if(i & set_bit_no)
			*x ^= i;
		else
			*y ^= i;
	}
}

87. Print a given matrix in spiral form

void spiralPrint(int M[][], int m, int n)
{
	int k = 0, l = 0;

	while(k < m && l < n)
	{
		for(int j = l; j < n; j++)
			printf("%d", M[k][j]);
		k++;

		for(int i = k; i < m; i++)
			printf("%d", M[i][n - 1]);
		n--;

		if(k < m)
		{
			for(int j = n - 1; j >= l; j--)
				printf("%d", M[m - 1][j]);
			m--;
		}

		if(l < n)
		{
			for(int i = m - 1; i >= k; i--)
				printf("%d", M[i][l]);
			l++;
		}
	}
}

Time complexity = O(m * n)

88. Design and Implement Special Stack Data Structure

/*
currMin < prevMin
currMin - prevMin < 0
currMin + currMin - prevMin < currMin
2 * currMin - prevMin < currMin
*/

class minStack
{
	stack<int> s;
	int min;
public:
	void push(int element)
	{
		if(s.empty())
		{
			s.push(element);
			min = element;
		}
		else
		{
			if(element < min)
			{
				int prevMin = min;
				int currMin = element;
				int encode = 2 * currMin - prevMin;
				s.push(encode);
				min = currMin;
			}
			else
				s.push(element);
		}
	}

	int topandpop()
	{
		if(s.empty())
		{
			printf("Stack underflow");
			return -1;
		}
		else
		{
			int element = s.top();
			s.pop();

			if(element < min)
			{
				int currMin = min;
				int encode = element;
				int prevMin = 2 * currMin - encode;
				min = prevMin;
				return element;
			}
			else
				return element;
		}
	}

	int getMin()
	{
		if(s.empty())
			return -1;
		return min;
	}
};

89. Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

void modifyMatrix(int M[][], int m, int n)
{
	int row[m];
	memset(row, 0, sizeof(row));

	int col[n];
	memset(col, 0, sizeof(col));

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(M[i][j] == 1)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(row[i] == 1 || col[j] == 1)
			{
				M[i][j] = 1;
			}
		}
	}
}

90. Median in a stream of integers (running integers)

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;

void add_number(int element)
{
	if(max_heap.size() == 0 || element <= max_heap.top())
		max_heap.push(element);
	else
		min_heap.push(element);
}

void balance()
{
	int min_heap_size = min_heap.size();
	int max_heap_size = max_heap.size();

	if(max_heap_size - min_heap_size > 1)
	{
		min_heap.push(max_heap.top());
		max_heap.pop();
	}
	else if(min_heap_size - max_heap_size > 1)
	{
		max_heap.push(min_heap.top());
		min_heap.pop();
	}
}

float getMedian()
{
	if(max_heap.size() == min_heap.size())
		return (max_heap.top() + min_heap.top()) / 2.0;
	else if(max_heap.size() > min_heap.size())
		return max_heap.top();
	else
		return min_heap.top();
}

void running_median(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		add_number(a[i]);
		balance();
		printf("%f", getMedian());
	}
}

//TODO
Time complexity = O(n log n)
Space complexity = O(n)

91. Min Cost Path

int minCostPath(int M[][], int m, int n)
{
	int DP[m][n];
	DP[0][0] = M[0][0];

	for(int j = 1; j < n; j++)
		DP[0][j] = DP[0][j - 1] + M[0][j];

	for(int i = 1; i < m; i++)
		DP[i][0] = DP[i - 1][0] + M[i][0];

	for(int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			DP[i][j] = min(DP[i - 1][j], DP[i][j - 1]) + M[i][j];
		}
	}

	return DP[m - 1][n - 1];
}

92. Add two numbers represented by linked lists

struct node* addLists(struct node* a, struct node* b)
{
	struct node* result = NULL;
	struct node* prev = NULL;
	int carry = 0;

	while(a != NULL || b != NULL)
	{
		int sum = (a ? a->data : 0) + (b ? b->data : 0) + carry;

		struct node* temp = newNode(sum % 10);
		carry = sum / 10;

		if(result == NULL)
			result = temp;
		else
			prev->next = temp;

		prev = temp;

		a = a ? a->next : NULL;
		b = b ? b->next : NULL;
	}

	if(carry)
		temp->next = newNode(carry);

	return result;
}

93. Find a Fixed Point (Value equal to index) in a given array

int fixedPointNoDup(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(mid == a[mid])
			return mid;
		else if(mid < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

94. Length of the longest subtring without repeating characters

int longestSubstring(char* str)
{
	unordered_set<char> hash;
	int max_len = INT_MIN;

	int begin = 0;
	for(int end = 0; str[end]; end++)
	{
		if(hash.find(str[end]) == hash.end())
		{
			hash.insert(str[end]);
			max_len = max(max_len, hash.size());
		}
		else
		{
			while(begin < end)
			{
				if(str[begin] == str[end])
				{
					begin++;
					break;
				}
				hash.erase(str[begin]);
				begin++;
			}
		}
	}

	return max_len;
}

95. Connect nodes at same level

void connectNodes(struct node* root)
{
	if(root == NULL)
		return;

	queue<struct node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();

		if(temp != NULL)
		{
			temp->nextRight = q.front();

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		else
		{
			if(!q.empty())
				q.push(NULL);
		}
	}
}

96. Find the maximum element in an array which is first increasing and then decreasing

int maxElementBitonic(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		if(low == high)
			return a[low];
		else if(high == low + 1)
			return max(a[low], a[high]);
		else
		{
			int mid = low + (high - low) / 2;
			if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
				return a[mid];
			else if(a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
				low = mid + 1;
			else if(a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
				high = mid - 1;
		}
	}

	return -1;
}

97. Sorted Array to Balanced BST

struct node* sortedArrToBST(int a[], int start, int end)
{
	if(start > end)
		return NULL;

	int mid = start + (end - start) / 2;
	struct node* root = newNode(a[mid]);
	root->left = sortedArrToBST(a, start, mid - 1);
	root->right = sortedArrToBST(a, mid + 1, end);
	return root;
}

Time complexity = O(n)

98. Minimum number of jumps to reach end

int minJumps(int a[], int n)
{
	if(a[0] == 0)
		return -1;

	int ladder = a[0];
	int stairs = a[0];
	int jump = 1;

	for(int i = 1; i < n; i++)
	{
		if(i == n - 1)
			return jump;

		ladder = max(ladder, i + a[i]);
		stairs--;

		if(stairs == 0)
		{
			if(i == ladder)
				return -1;
			jump++;
			stairs = ladder - i;
		}
	}
}

99. Matrix Chain Multiplication

int MCM(int a[], int size)
{
	int n = size - 1;
	int DP[n + 1][n + 1];

	for(int i = 1; i <= n; i++)
		DP[i][i] = 0;

	for(int L = 2; L <= n; L++)
	{
		for(int i = 1; i <= n - L + 1; i++)
		{
			int j = i + L - 1;

			DP[i][j] = INT_MAX;
			for(int k = i; k < j; k++)
			{
				int temp = DP[i][k] + DP[k + 1][j] + a[i - 1] * a[k] * a[j];
				if(temp < DP[i][j])
					DP[i][j] = temp;
			}
		}
	}

	return DP[1][n];
}

Time complexity = O(n^3)
Space complexity = O(n^2)

100. Convert a given tree to its Sum Tree

int convertSumTree(struct node* root)
{
	if(root == NULL)
		return 0;

	int old_data = root->data;
	root->data = convertSumTree(root->left) + convertSumTree(root->right);
	return root->data + old_data;
}

101. Find the largest BST subtree in a given Binary Tree

struct Info
{
	int min;
	int max;
	int size;
	int ans;
	bool isBST;
};

Info largestBST(struct node* root)
{
	if(root == NULL)
		return {INT_MAX, INT_MIN, 0, 0, true};
	if(root->left == NULL && root->right == NULL)
		return {root->data, root->data, 1, 1, true};

	Info l = largestBST(root->left);
	Info r = largestBST(root->right);

	Info result;
	if(l.isBST && r.isBST && root->data > l.max && root->data < r.min)
	{
		result.min = min(root->data, min(l.min, r.min));
		result.max = max(root->data, max(l.max, r.max));
		result.size = 1 + l.size + r.size;
		result.ans = result.size;
		result.isBST = true;
	}
	else
	{
		result.size = 1 + l.size + r.size;
		result.ans = max(l.ans, r.ans);
		result.isBST = false;
	}

	return result;
}

102. Vertical Sum in a given Binary Tree

void verticalSum(struct node* root)
{
	if(root == NULL)
		return;

	unordered_map<int, int> hash;
	int hd = 0;

	queue<pair<struct node*, int>> q;
	q.push({root, hd});

	while(!q.empty())
	{
		pair<struct node*, int> temp_pair = q.front();
		q.pop();

		struct node* temp = temp_pair.first;
		hd = temp_pair.second;

		hash[hd] += temp->data;

		if(temp->left)
			q.push({temp->left, hd - 1});
		if(temp->right)
			q.push({temp->right, hd + 1});
	}

	for(auto it = hash.begin(); it != hash.end(); it++)
		printf("%d %d", it->first, it->second);
}

103. Activity Selection Problem

bool compare(Activity a1, Activity a2)
{
	return a1.end < a2.end;
}

void activity_selection(Activity a[], int n)
{
	sort(a, a + n, compare);

	printf("%d %d", a[0].start, a[0].end);
	int prev = 0;

	for(int i = 1; i < n; i++)
	{
		if(a[i].start >= a[prev].end)
		{
			printf("%d %d", a[i].start, a[i].end);
			prev = i;
		}
	}	
}

104. Union and Intersection of two Linked Lists

void storeInHash(struct node* a, struct node* b, unordered_map<int, int>& hash)
{
	while(a != NULL)
	{
		hash[a->data]++;
		a = a->next;
	}

	while(b != NULL)
	{
		hash[b->data]++;
		b = b->next;
	}
}

void push(struct node** head, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

struct node* getUnion(unordered_map<int, int> hash)
{
	struct node* result = NULL;
	for(auto it = hash.begin(); it != hash.end(); it++)
		push(&result, it->first);
	
	return result;
}

struct node* getIntersection(unordered_map<int, int> hash)
{
	struct node* result = NULL;
	for(auto it = hash.begin(); it != hash.end(); it++)
	{
		if(it->second == 2)
			push(&result, it->first);
	}

	return result;
}

void display(struct node* head)
{
	while(head != NULL)
	{
		printf("%d", head->data);
		head = head->next;
	}
}

void unionIntersection(struct node* a, struct node* b)
{
	unordered_map<int, int> hash;

	storeInHash(a, b, &hash);

	struct node* unionHead = getUnion(hash);
	display(unionHead);

	struct node* interHead = getIntersection(hash);
	display(interHead);
}

105. Detect Cycle in a Directed Graph

bool hasCycleUtil(int u, int N, vector<int>* adj, int* color)
{
    color[u] = 1;
	
	for(auto it = adj[u].begin(); it != adj[u].end(); it++)
	{
	    int v = *it;
	   	if(color[v] == 0 )
		{
			if(hasCycleUtil(v, N, adj, color))
				return true;
		}
		else if(color[v] == 1)
			return true;
	}

	color[u] = 2;
	return false;
}

bool hasCycle(int N, vector<int>* adj)
{
	int color[N + 1];
	for(int i = 1; i <= N; i++)
		color[i] = 0;

	for(int i = 1; i <= N; i++)
	{
		if(color[i] == 0)
		{
			if(hasCycleUtil(i, N, adj, color))
				return true;
		}
	}

	return false;
}

Time complexity = O(V + E)
Space complexity = O(V)

106. Check whether two strings are anagram of each other

bool isAnagram(char* str1, char* str2)
{
	int count[256];
	memset(count, 0, sizeof(count));

	for(int i = 0; str1[i] && str2[i]; i++)
	{
		count[str1[i]]++;
		count[str2[i]]--;
	}

	if(str1[i] || str2[i])
		return false;

	for(int i = 0; i < 256; i++)
	{
		if(count[i] != 0)
			return false;
	}

	return true;
}

107. Longest Palindromic subsequence

int LPS(char* X)
{
	char Y[30];
	strcpy(Y, X);
	strrev(Y);
	return LPSUtil(X, Y);
}

108. Find subarray with given sum

bool isSubarraySum(int a[], int n, int sum)
{
	unordered_map<int, int> hash;
	int curr_sum = 0;

	for(int i = 0; i < n; i++)
	{
		curr_sum += a[i];

		if(curr_sum == sum)
		{
			printf("0 %d", i);
			return true;
		}

		if(hash.find(curr_sum - sum) != hash.end())
		{
			printf("%d %d", hash[curr_sum - sum] + 1, i);
			return true;
		}
		else
			hash[curr_sum] = i;
	}

	return false;
}

109. Maximum Sum Increasing Subsequence

int MSIS(int a[], int n)
{
	int DP[n];

	for(int i = 0; i < n; i++)
		DP[i] = a[i];

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(a[i] > a[j] && DP[j] + a[i] > DP[i])
			{
				DP[i] = DP[j] + a[i];
			}
		}
	}

	int max_msis = INT_MIN;
	for(int i = 0; i < n; i++)
		max_msis = max(max_msis, DP[i]);
	return max_msis;
}

110. Find a triplet that sum to a given value

void tripletSum(int a[], int n, int sum)
{
	sort(a, a + n);

	for(int i = 0; i < n - 2; i++)
	{
		int l = i + 1;
		int r = n - 1;

		while(l < r)
		{
			int curr_sum = a[i] + a[l] + a[r];

			if(curr_sum == sum)
			{
				printf("%d %d %d", a[i], a[l], a[r]);
				return;
			}
			else if(curr_sum < sum)
				l++;
			else
				r--;
		}
	}

	printf("Not found");
}

//TODO
Time complexity = O(n^2)

111. Find the smallest positive number missing from an unsorted array

int smallestPositive(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] <= 0 || a[i] > n)
			continue;

		int val = a[i];
		while(val != a[val - 1])
		{
			int next_val = a[val - 1];
			a[val - 1] = val;
			val = next_val;

			if(val <= 0 || val > n)
				break;
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(a[i] != i + 1)
			return i + 1;
	}

	return n + 1;
}

112. Merge two BSTs with limited extra space

int size(struct node* root)
{
	if(root == NULL)
		return 0;

	return 1 + size(root->left) + size(root->right);
}

void storeInorder(struct node* root, int a[], int* index)
{
	if(root == NULL)
		return;

	storeInorder(root->left, a, index);

	a[(*index)++] = root->data;

	storeInorder(root->right, a, index);
}

void mergeArrays(int a[], int m, int b[], int n, int c[])
{
	int i = 0, j = 0, k = 0;

	while(i < m && j < n)
	{
		if(a[i] <= b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	while(i < m)
		c[k++] = a[i++];

	while(j < n)
		c[k++] = b[j++]; 
}

void merge_BSTS(struct node* a, struct node* b)
{
	int n1 = size(a);
	int a_array[n1];
	int index = 0;
	storeInorder(a, a_array, &index);

	int n2 = size(b);
	int b_array[n2];
	index = 0;
	storeInorder(b, b_array, &index);

	int c_array[n1 + n2];
	mergeArrays(a_array, n1, b_array, n2, c_array);

	return sortedArrToBST(c_array, 0, n1 + n2 - 1);
}

113. The Celebrity Problem

int findCelebrity(int n, vector<vector<int>> knowMatrix)
{
	int knows[n + 1];
	int knownBy[n + 1];

	memset(knows, 0, sizeof(knows));
	memset(knownBy, 0, sizeof(knownBy));

	for(int i = 0; i < knowMatrix.size(); i++)
	{
		int a = knowMatrix[i][0];
		int b = knowMatrix[i][1];

		knows[a]++;
		knownBy[b]++;
	}

	for(int i = 1; i <= n; i++)
	{
		if(knows[i] == 0 && knownBy[i] == n - 1)
			return i;
	}

	return -1;
}

114. Find a sorted subsequence of size 3 in linear time

void sortedSubsequence(int a[], int n)
{
	int smaller[n];
	smaller[0] = -1;
	int min = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[min])
			smaller[i] = min;
		else
		{
			smaller[i] = -1;
			min = i;
		}
	}

	int greater[n];
	greater[n - 1] = -1;
	int max = n - 1;
	for(int i = n - 2; i >= 0; i--)
	{
		if(a[i] < a[max])
			greater[i] = max;
		else
		{
			greater[i] = -1;
			max = i;
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(smaller[i] != -1 && greater[i] != -1)
		{
			printf("%d %d %d", a[smaller[i]], a[i], a[greater[i]]);
			return;
		}
	}

	printf("No such sorted subsequence");
}

115. Binary Tree to Binary Search Tree Conversion

void arrayToBST(int a[], struct node* root, int* index)
{
	if(root == NULL)
		return;

	arrayToBST(a, root->left, index);

	root->data = a[(*index)++];

	arrayToBST(a, root->right, index);
}

void BT_BST(struct node* root)
{
	int n = size(root);
	int a[n];
	int index = 0;	
	storeInorder(root, a, &index);

	sort(a, a + n);

	index = 0;
	arrayToBST(a, root, &index);
}

116. Palindrome Partitioning

int minCuts(char* str)
{
	int n = strlen(str);

	bool DP[n][n];
	int C[n][n];

	for(int i = 0; i < n; i++)
	{
		DP[i][i] = true;
		C[i][i] = 0;
	}

	for(int L = 2; L <= n; L++)
	{
		for(int i = 0; i < n - L + 1; i++)
		{
			int j = i + L - 1;

			if(L == 2)
				DP[i][j] = str[i] == str[j];
			else
				DP[i][j] = str[i] == str[j] && DP[i + 1][j - 1];

			if(DP[i][j])
				C[i][j] = 0;
			else
			{
				C[i][j] = INT_MAX;
				for(int k = i; k < j; k++)
				{
					int temp = C[i][k] + C[k + 1][j] + 1;
					if(temp < C[i][j])
						C[i][j] = temp;
				}
			}
		}
	}

	return C[0][n - 1];
}

Time complexity = O(n^3)

117. Count total set bits in all numbers from 1 to n

int countSetBits(int n)
{
	int DP[n + 1];
	DP[0] = 0;
	DP[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		if(i % 2 == 0)
			DP[i] = DP[i / 2];
		else
			DP[i] = 1 + DP[i - 1];
	}

	int count = 0;
	for(int i = 0; i <= n; i++)
		count += DP[i];

	return count;
}

118. Largest subarray with equal number of 0s and 1s

int largestSubarray01(int a[], int n)
{
	unordered_map<int, int> hash;
	int curr_sum = 0;
	int max_len = INT_MIN;

	for(int i = 0; i < n; i++)
	{
		curr_sum += (a[i] == 0) ? -1 : 1;

		if(curr_sum == 0)
			max_len = i + 1;

		if(hash.find(curr_sum) != hash.end())
			max_len = max(max_len, i - hash[curr_sum]);
		else
			hash[curr_sum] = i;
	}

	return max_len;
}

119. Partition problem

bool isSubsetSum(int a[], int n, int sum)
{
	bool DP[n + 1][sum + 1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			if(i == 0)
				DP[i][j] = false;
			else if(j == 0)
				DP[i][j] = true;
			else if(a[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] || DP[i - 1][j - a[i - 1]];
		}
	}

	return DP[n][sum];
}

bool isPartition(int a[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];

	if(sum % 2 != 0)
		return false;
	else
		return isSubsetSum(a, n, sum / 2);
}

Time complexity = O(n * sum)

120. Maximum Product Subarray

void maxProductSubarray(int a[], int n)
{
	int curr_max = a[0];
	int curr_min = a[0];
	int max_so_far = a[0];

	for(int i = 0; i < n; i++)
	{
		if(a[i] < 0)
			swap(&curr_max, &curr_min);

		curr_max = max(curr_max * a[i], a[i]);
		curr_min = min(curr_min * a[i], a[i]);
		max_so_far = max(max_so_far, curr_max);
	}

	return max_so_far;
}

121. Find a pair with the given difference

bool pairDiff(int a[], int n, int diff)
{
	unordered_set<int> hash;

	for(int i = 0; i < n; i++)
	{
		if(hash.find(a[i] - diff) != hash.end())
		{
			printf("%d %d", a[i], a[i] - diff);
			return true;
		}
		else if(hash.find(a[i] + diff) != hash.end())
		{
			printf("%d %d", a[i], a[i] + diff);
			return true;
		}
		else
			hash.insert(a[i]);
	}

	return false;
}

122. Construct BST from given preorder traversal | Set 1

struct node* construct(int pre[], int n, int* index, int min, int max)
{
	if((*index) == n)
		return NULL;

	int key = pre[(*index)];
	struct node* root = NULL;

	if(key > min && key < max)
	{
		root = newNode(key);
		(*index)++;
		root->left = construct(pre, n, index, min, key - 1);
		root->right = construct(pre, n, index, key + 1, max);
	}

	return root;
}

Time complexity = O(n)

123. Find the Rotation Count in Rotated Sorted array

int rotationCount(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(mid > low && a[mid - 1] > a[mid])
			return mid;
		if(mid < high && a[mid] > a[mid + 1])
			return mid + 1;

		if(a[low] <= a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0;
}

124. Heap sort

void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && a[l] > a[largest])
		largest = l;
	if(r < n && a[r] > a[largest])
		largest = r;

	if(largest != i)
	{
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}

void heap_sort(int a[], int n)
{
	for(int i = n/2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for(int i = n - 1; i >= 0; i--)
	{
		swap(&a[i], &a[0]);
		heapify(a, i, 0);
	}	
}

Time complexity = O(n log n)

125. Maximum Length Chain of Pairs 

bool compare(Chain c1, Chain c2)
{
	return c1.end < c2.end;
}

int maxLenChainPairs(Chain a[], int n)
{
	sort(a, a + n, compare);

	int count = 1;
	int prev = 0;

	for(int i = 1; i < n; i++)
	{
		if(a[i].start >= a[prev].end)
		{
			count++;
			prev = i;
		}
	}

	return count;
}

126. Replace every element with the greatest element on right side

void replaceNxtGreater(int a[], int n)
{
	int max_from_right = a[n - 1];
	a[n - 1] = -1;
	
	for(int i = n - 2; i >= 0; i--)
	{
		int temp = a[i];
		a[i] = max_from_right;
		if(temp > max_from_right)
			max_from_right = temp;
	}
}

127. Box Stacking Problem

bool compare(Box a, Box b)
{
	return a.w * a.d > b.w * b.d;
}

int boxStack(Box a[], int n)
{
	Box rot[3 * n];

	int index = 0;
	for(int i = 0; i < n; i++)
	{
		rot[index].h = a[i].h;
		rot[index].w = min(a[i].w, a[i].d);
		rot[index].d = max(a[i].w, a[i].d);
		index++;

		rot[index].h = a[i].w;
		rot[index].w = min(a[i].h, a[i].d);
		rot[index].d = max(a[i].h, a[i].d);
		index++;

		rot[index].h = a[i].d;
		rot[index].w = min(a[i].h, a[i].w);
		rot[index].d = max(a[i].h, a[i].w);
		index++;
	}

	n = 3 * n;
	sort(rot, rot + n, compare);

	int DP[n];

	for(int i = 0; i < n; i++)
		DP[i] = rot[i].h;

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(rot[i].w < rot[j].w && rot[i].d < rot[j].d && DP[j] + rot[i].h > DP[i])
				DP[i] = DP[j] + rot[i].h;
		}
	}

	int max_height = INT_MIN;
	for(int i = 0; i < n; i++)
		max_height = max(max_height, DP[i]);

	return max_height;
}

Time complexity = O(n^2)
Space complexity = O(n)

128. Delete nth node from end of a linked list

void delNthFromEnd(struct node* head, int n)
{
	if(head == NULL)
		return;

	struct node* slowptr = head;
	struct node* fastptr = head;
	struct node* prev = NULL;

	for(int i = 1; i <= n - 1 && fastptr != NULL; i++)
		fastptr = fastptr->next;

	while(fastptr->next != NULL)
	{
		prev = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}

	prev->next = slowptr->next;
	free(slowptr);
}

129. Print path between any two nodes in a Binary Tree

void printPathFromRoot(struct node* root, int k, vector<int> path)
{
	if(root == NULL)
		return;

	path.push_back(root->data);

	if(root->data == k)
		return;

	printPathFromRoot(root->left, k, path);
	printPathFromRoot(root->right, k, path);
}

void printPathTwoNodes(struct node* root, int k1, int k2)
{
	vector<int> path1;
	printPathFromRoot(root, k1, path1);

	vector<int> path2;
	printPathFromRoot(root, k2, path2);

	int intersection = -1;
	int i = 0, j = 0;
	while(i < path1.size() && j < path2.size())
	{
		if(path1[i] == path2[j])
		{
			intersection = i;
			i++;
			j++;
		}
		else
			break;
	}

	for(int i = path1.size() - 1; i > intersection; i--)
		printf("%d", path1[i]);

	for(int i = intersection; i < path2.size(); i++)
		printf("%d", path2[i]);
}

130. Merge k sorted arrays

typedef pair<int, pair<int, int>> ppi;
void mergeKSortedArrays(vector<vector<int>> a, int k)
{
	priority_queue<ppi, vector<ppi>, greater<ppi>> min_heap;
	vector<int> result;

	for(int i = 0; i < k; i++)
		min_heap.push({a[i][0], {i, 0}});

	while(!min_heap.empty())
	{
		ppi temp = min_heap.top();
		min_heap.pop();

		int element = temp.first;
		int array_no = temp.second.first;
		int index = temp.second.second;

		result.push_back(element);

		if(index + 1 < a[array_no].size())
			min_heap.push({a[array_no][index + 1], {array_no, index + 1}});
	}

	for(int i = 0; i < result.size(); i++)
		printf("%d", result[i]);
}

Time complexity = O(kn log k)

131. Find four elements that sum to a given value

void 4Sum(int a[], int n, int four_sum)
{
	unordered_map<int, vector<pair<int, int>>> hash;

	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int pair_sum = a[i] + a[j];

			if(hash.find(four_sum - pair_sum) != hash.end())
			{
				vector<pair<int, int>> v = hash[four_sum - pair_sum];
				for(int k = 0; k < v.size(); k++)
				{
					pair<int, int> p = v[k];
					if(i != p.first && j != p.first && i != p.second && j != p.second)
					{
						printf("%d %d %d %d", i, j, p.first, p.second);
						return;
					}
				}
			}
			else
				hash[pair_sum].push_back({i, j});
		} 
	}
}

132. Find the row with maximum number of 1s

int firstOcc(int a[], int low, int high)
{
	int first = -1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(a[mid] == 1)
		{
			first = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return first;
}

void maxRow1(int M[][], int m, int n)
{
	int max_row = 0;

	int j = firstOcc(M[0], 0, n - 1);
	if(j == -1)
	{
		max_row = -1;
		j = n - 1;
	}

	for(int i = 1; i < m; i++)
	{
		while(M[i][j] == 1 && j >= 0)
		{
			j--;
			max_row = i;
		}
	}

	return max_row;
}

//todo
Time complexity = O(m + n)

133. Lowest Common Ancestor in a Binary Tree

struct node* LCA(struct node* root, int k1, int k2)
{
	if(root == NULL)
		return NULL;

	if(root->data == k1 || root->data == k2)
		return root;

	struct node* left = LCA(root->left, k1, k2);
	struct node* right = LCA(root->right, k1, k2);

	if(left != NULL && right != NULL)
		return root;
	else if(left != NULL)
		return left;
	else
		return right;
}

Time complexity : O(n)

134. Find distance between two nodes of a Binary Tree

int findLevel(struct node* root, int k, int level)
{
	if(root == NULL)
		return -1;

	if(root->data == k)
		return level;

	int left = findLevel(root->left, k, level + 1);
	if(left == -1)
		return findLevel(root->right, k, level + 1);
	return left;
}

int distanceTwoNodes(struct node* root, int k1, int k2)
{
	if(root == NULL)
		return -1;

	struct node* ancestor = LCA(root, k1, k2);

	int l = findLevel(ancestor, k1, 0);
	int r = findLevel(ancestor, k2, 0);

	return l + r;
}

135. Minimum Number of Platforms Required for a Railway/Bus Station

int minPlatforms(int a[], int d[], int n)
{
	sort(a, a + n);
	sort(d, d + n);

	int platforms = 0;
	int result = 0;

	int i = 0, j = 0;
	while(i < n && j < n)
	{
		if(a[i] <= d[j])
		{
			i++;
			platforms++;
			result = max(result, platforms);
		}
		else
		{
			j++;
			platforms--;
		}
	}

	return result;
}

136. Merge sort for Linked Lists

void splitHalf(struct node* head, struct node** first, struct node** second)
{
	struct node* prev = NULL;
	struct node* slowptr = head;
	struct node* fastptr = head;

	while(fastptr != NULL && fastptr->next != NULL)
	{
		prev = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}

	*first = head;
	prev->next = NULL;
	*second = slowptr;
}

void merge_sort(struct node** head)
{
	if((*head) == NULL || (*head)->next == NULL)
		return;

	struct node* first = NULL;
	struct node* second = NULL;
	splitHalf(*head, &first, &second);

	merge_sort(&first);
	merge_sort(&second);

	*head = mergeSortedLists(first, second);
}

Note: BST can be constructed using two traversals or only preorder
Given a sorted array, u can construct 2nCn/(n+1) BST - one way could be building balanced BST 

137. Serialize and Deserialize a Binary Tree

vector<string> split(string str, char delim)
{
	vector<string> result;
	stringstream s(str);
	while(s.good())
	{
		string temp;
		getline(s, temp, delim);
		result.push_back(temp);
	}

	return result;
}

string serialize(struct node* root) 
{
	if(root == NULL) 
        return "null";
        
    string result = "";
    
    queue<struct node*> q;
    q.push(root);

    while(!q.empty())
    {
        struct node* temp = q.front();
        q.pop();
            
       	if(temp == NULL)
            result += "null,";
        else
        {
            result += to_string(temp->data) + ",";
    	    q.push(temp->left);
           	q.push(temp->right);
        }
    }
    
    result.pop_back();
	return result;
}

struct node* deserialize(string data)
{
    vector<string> a = split(data, ',');
    if(a[0] == "null")
        return NULL;

    queue<struct node*> q;
    
    int i = 0;
    struct node* root = newNode(a[i]);
    q.push(root);
    i++;
        
    while(i < a.size())
    {
        struct node* parent = q.front();
        q.pop();
            
		struct node* left = NULL;
        if(a[i] != "null")    
        {
            left = newNode(a[i]);
            q.push(left);
        }
        i++;
        parent->left = left;
            
        if(i < a.size()) 
        {
            struct node* right = NULL;
            if(a[i] != "null")
            {
                right = newNode(a[i]);
                q.push(right);
            }
            i++;
            parent->right = right;
		}
	}
   	return root;
}

138. Shuffle an array

void shuffle(int a[], int n)
{
	srand(time(NULL));

	for(int i = n - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(&a[i], &a[j]);
	}
}

139. Find the number of islands

int row[4] = {-1, 0, 0, 1};
int col[4] = {0, -1, 1, 0};

bool isSafe(int x, int y, vector<vector<int>> M, int m, int n, vector<vector<int>> visited)
{
	return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && M[x][y];
}

int countIslandsUtil(int x, int y, vector<vector<int>> M, int m, int n, vector<vector<int>>& visited)
{
	visited[x][y] = 1;

	for(int k = 0; k < 4; k++)
	{
		int next_x = x + row[k];
		int next_y = y + col[k];

		if(isSafe(next_x, next_y, M, m, n, visited))
			countIslandsUtil(next_x, next_y, M, m, n, visited);
	}
}

int countIslands(vector<vector<int>> M)
{
	int m = M.size();
	int n = M[0].size();

	vector<vector<int>> visited(m, vector<int>(n, 0));

	int count = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(!visited[i][j] && M[i][j])
			{
				count++;
				countIslandsUtil(i, j, M, m, n, visited);
			}
		}
	}

	return count;
}

Time complexity = O(mn)
Space complexity = O(mn)

140. Given a number, find the next smallest palindrome

void nextPalindromeUtil(int num[], int n)
{
	int mid = n / 2;
	int i = mid - 1;
	int j = n % 2 == 0 ? mid : mid + 1;

	while(i >= 0 && num[i] == num[j])
	{
		i--;
		j++;
	}

	bool leftSmaller = false;
	if(i < 0 || num[i] < num[j])
		leftSmaller = true;

	while(i >= 0)
	{
		num[j] = num[i];
		i--;
		j++;
	}

	if(leftSmaller)
	{
		int sum, carry = 1;
		i = mid - 1;

		if(n % 2 == 1)
		{
			sum = num[mid] + carry;
			num[mid] = sum % 10;
			carry = sum / 10;
			j = mid + 1;
		}
		else
			j = mid;

		while(i >= 0)
		{
			sum = num[i] + carry;
			num[i] = sum % 10;
			carry = sum / 10;
			num[j] = num[i];
			i--;
			j++;
		}
	}
}

bool hasAllNines(int num[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(num[i] != 9)
			return false;
	}

	return true;
}

void nextPalindrome(int num[], int n)
{
	if(hasAllNines(num, n))
	{
		printf("1");
		for(int i = 1; i <= n - 1; i++)
			printf("0");
		printf("1");
		return;
	}

	nextPalindromeUtil(num, n);

	for(int i = 0; i < n; i++)
		printf("%d", num[i]);
}     

141. Boundary Traversal of binary Tree

void printBoundaryLeft(struct node* root)
{
	if(root == NULL)
		return;

	if(root->left != NULL)
	{
		printf("%d", root->data);
		printBoundaryLeft(root->left);
	}
	else if(root->right != NULL)
	{
		printf("%d", root->data);
		printBoundaryLeft(root->right);
	}
}

void printLeaves(struct node* root)
{
	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL)
		printf("%d", root->data);

	printLeaves(root->left);
	printLeaves(root->right);
}

void printBoundaryRight(struct node* root)
{
	if(root == NULL)
		return;

	if(root->right != NULL)
	{
		printBoundaryRight(root->right);
		printf("%d", root->data);
	}
	else if(root->left != NULL)
	{
		printBoundaryRight(root->left);
		printf("%d", root->data);
	}
}

void boundaryTraversal(struct node* root)
{
	if(root == NULL)
		return;

	printBoundaryLeft(root);
	printLeaves(root);
	printBoundaryRight(root);
}

Time complexity = O(n)

142. Two nodes of a BST are swapped, correct the BST

void recoverBSTUtil(struct node* root, struct node** prev, struct node** first, struct node** last)
{
	if(root == NULL)
		return;

	recoverBSTUtil(root->left, prev, first, last);

	if((*prev) != NULL)
	{
		if((*prev)->data > root->data)
		{
			if((*first) == NULL)
				*first = prev;
			else
				*last = root;
		}
	}
	*prev = root;

	recoverBSTUtil(root->right, prev, first, last);
}

void recoverBST(struct node* root)
{
	if(root == NULL)
		return;

	struct node* prev = NULL, *first = NULL, *last = NULL;
	recoverBSTUtil(root, &prev, &first, &last);
	swap(&first->data, &last->data);
}

143. Convert a given Binary Tree to Doubly Linked list

void BT_to_DLL(struct node* root, struct node** head)
{
	if(root == NULL)
		return;

	BT_to_DLL(root->right, head);

	root->right = *head;
	if((*head) != NULL)
		(*head)->left = root;
	*head = root;

	BT_to_DLL(root->left, head);
}

144. Pythagorean Triplet in an array

void pythagoreanTriplet(int a[], int n)
{
	for(int i = 0; i < n; i++)
		a[i] = a[i] * a[i];

	sort(a, a + n);

	for(int i = n - 1; i >= 2; i--)
	{
		int l = 0;
		int r = i - 1;

		while(l < r)
		{
			if(a[l] + a[r] == a[i])
			{
				printf("%d %d %d", a[l], a[r], a[i]);
				return;
			}
			else if(a[l] + a[r] < a[i])
				l++;
			else
				r--;
		}
	}

	printf("No such triplet");
}

Time complexity = O(n^2)

145. Find the largest multiple of 3 from array of digits

void sort(int num[], int n)
{
	int count[10] = {0};
	for(int i = 0; i < n; i++)
		count[num[i]]++;

	int index = 0;
	for(int i = 0; i < 10; i++)
	{
		while(count[i]--)
			num[index++] = i;
	}

}

void printArray(int num[], int n)
{
	for(int i = n - 1; i >= 0; i--)
		printf("%d", num[i]);
}

void removeAndPrintArray(int num[], int n, int index1, int index2 = -1)
{
	for(int i = n - 1; i >= 0; i--)
	{
		if(i != index1 && i != index2)
			printf("%d", num[i]);
	}
}

void largestMultipleOf3(int num[], int n)
{
	sort(num, n);

	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += num[i];

	int remainder = sum % 3;

	if(remainder == 0)
	{
		printArray(num, n);
		return;
	}
	else if(remainder == 1)
	{
		int rem_2[2];
		rem_2[0] = -1, rem_2[1] = -1;

		for(int i = 0; i < n; i++)
		{
			if(num[i] % 3 == 1)
			{
				removeAndPrintArray(num, n, i);
				return;
			}
			else if(num[i] % 3 == 2)
			{
				if(rem_2[0] == -1)
					rem_2[0] = i;
				else if(rem_2[1] == -1)
					rem_2[1] = i;
			}
		}

		if(rem_2[0] != -1 && rem_2[1] != -1)
		{
			removeAndPrintArray(num, n, rem_2[0], rem_2[1]);
			return;
		}
	}
	else
	{
		int rem_1[2];
		rem_1[0] = -1, rem_1[1] = -1;

		for(int i = 0; i < n; i++)
		{
			if(num[i] % 3 == 2)
			{
				removeAndPrintArray(num, n, i);
				return;
			}
			else if(num[i] % 3 == 1)
			{
				if(rem_1[0] == -1)
					rem_1[0] = i;
				else if(rem_1[1] == -1)
					rem_1[1] = i;
			}
		}

		if(rem_1[0] != -1 && rem_1[1] != -1)
		{
			removeAndPrintArray(num, n, rem_1[0], rem_1[1]);
			return;
		}
	}

	printf("Not possible");
}

146. Print all elements in sorted order from row and column wise sorted matrix

typedef pair<int, pair<int, int>> ppi;
void printSortedOrder(int M[][], int m, int n)
{
	priority_queue<ppi, vector<ppi>, greater<ppi>> min_heap;
	vector<int> result;

	for(int i = 0; i < m; i++)
		min_heap.push({M[i][0], {i, 0}});

	while(!min_heap.empty())
	{
		ppi temp = min_heap.top();
		min_heap.pop();

		int element = temp.first;
		int row = temp.second.first;
		int col = temp.second.second;

		result.push_back(element);

		if(col + 1 < n) 
			min_heap.push({M[row][col + 1], {row, col + 1}});
	}

	for(int i = 0; i < result.size(); i++)
		printf("%d", result[i]);
}

Time complexity = O(mn log m)

147. LRU Cache Implementation

class LRUCache
{
	unordered_map<int, pair<int, list<int>::iterator>> hash;
	list<int> cache;
	int capacity;
public:
	LRUCache(int capacity)
	{
		this.capacity = capacity;
	}

	void put(int key, int value)
	{
		if(hash.find(key) != hash.end())
		{
			list<int>::iterator pos_key = hash[key].second;
			cache.erase(pos_key);

			cache.push_front(key);
			hash[key] = make_pair(value, cache.begin());
		}
		else
		{
			if(hash.size() == capacity)
			{
				hash.erase(cache.back());
				cache.pop_back();
			}
			
			cache.push_front(key);
			hash[key] = make_pair(value, cache.begin());
		}
	}

	int get(int key)
	{
		if(hash.find(key) != hash.end())
		{
			int value = hash[key].first;

			list<int>::iterator pos_key = hash[key].second;
			cache.erase(pos_key);

			cache.push_front(key);
			hash[key] = make_pair(value, cache.begin());

			return value;
		}
		else
			return -1;
	}
};

148. Print unique rows in a given boolean matrix

void printUniqueRows(int M[][], int m, int n)
{
	unordered_set<string> hash;

	for(int i = 0; i < m; i++)
	{
		string temp = "";
		for(int j = 0; j < n; j++)
			temp += to_string(M[i][j]) + " ";

		hash.insert(temp);
	}

	for(auto it = hash.begin(); it != hash.end(); it++)
		printf("%s", *it);
}

149. Flattening a Linked List

struct node* flatten(struct node* head)
{
	if(head == NULL || head->right == NULL)
		return head;

	return mergeSortedLists(head, flatten(head->right));
}

150. Find the element that appears once

int getNonRepeating(int a[], int n)
{
	int NUM_BITS = 32;

	int result = 0;
	for(int i = 0; i < NUM_BITS; i++)
	{
		int bit = 1 << i;
 
		int count = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[j] & bit)
				count++;
		}

		if(count % 3 != 0)
			result |= bit;
	}

	return result;
}

151. Count the number of possible triangles

int countTriangles(int a[], int n)
{
	sort(a, a + n);

	int count = 0;
	for(int i = n - 1; i >= 2; i--)
	{
		int l = 0;
		int r = i - 1;

		while(l < r)
		{
			if(a[l] + a[r] > a[i])
			{
				count += r - l;
				r--;
			}
			else
				l++;
		}
	}

	return count;
}

152. Longest Palindromic Substring

string preprocess(string str)
{
	string text = "$#";
	for(int i = 0; i < str.size(); i++)
		text += str[i] + "#";
	text += "@";
	return text;
}

void longestPalindromeSubstr(string text)
{
	int N = text.length();
	vector<int> L(N, 0);

	int R = 1, C = 1;
	int maxLPSlen = INT_MIN, maxLPSCentre;

	for(int i = 2; i < N; i++)
	{
		int mirror = 2*C - i;
		if(i < R)
			L[i] = min(L[mirror, R - i]);

		while(text[i + L[i] + 1] == text[i - L[i] - 1])
			L[i]++;

		if(i + L[i] > R)
		{
			C = i;
			R = i + L[i];
		}

		if(L[i] > maxLPSlen)
		{
			maxLPSlen = L[i];
			maxLPSCentre = i;
		}
	}

	int start = (maxLPSCentre - maxLPSlen) / 2;
	int end = start + maxLPSlen - 1;
	for(int i = start; i <= end; i++)
		cout << str[i];
}

153. Given a sequence of words, print all anagrams together

void groupAnagrams(vector<string> arr)
{
	unordered_map<string, vector<string>> hash;

	for(int i = 0; i < arr.size(); i++)
	{
		string temp = arr[i];

		int count[256] = {0};
		for(int j = 0; temp[j]; j++)	
			count[temp[j]]++;

		string temp_key = "";
		for(int j = 0; j < 256; j++)
			temp_key += to_string(count[j]) + "#";

		hash[temp_key].push_back(temp);
	}

	for(auto it = hash.begin(); it != hash.end(); it++)
	{
		for(int i = 0; i < it->second.size(); i++)
			cout << it->second[i] << " ";
		cout << endl;
	}
}

Time complexity = O(n * k), where n is the size of arr and k is the maximum length of the string in those arrays

154. Pascals Triangle

void pascalsTriangle(int line)
{
	for(int n = 0; n < line; n++)
	{
		int C;
		for(int r = 0; r <= n; r++)
		{
			if(r == 0)
				C = 1;
			else
				C *= (n - r + 1) / r;

			printf("%d", C);
		}

		printf("\n");
	}
}

155. Expression Evaluation

int applyOp(int a, int b, char op)
{
	switch(op)
	{
		case '+' : return a + b;
		case '-' : return a - b;
		case '*' : return a * b;
		case '/' : return a / b;
	}
}

int prcd(char symbol)
{
	switch(symbol)
	{
		case '+' : 
		case '-' : return 1;
		case '*' : 
		case '/' : return 2;
	}
}

int expressionEvaluation(char* exp)
{
	stack<int> s;
	stack<char> op;

	for(int i = 0; exp[i]; i++)
	{
		if(isdigit(exp[i]))
			s.push(exp[i] - '0');
		else if(exp[i] == '(')
			ops.push(exp[i]);
		else if(exp[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = s.top();
				s.pop();
				
				int val1 = s.top();
				s.pop();

				char op = ops.top();
				ops.pop();

				s.push(applyOp(val1, val2, op));
			}

			ops.pop();
		}
		else
		{
			while(!ops.empty() && prcd(ops.top()) >= prcd(exp[i]))
			{
				int val2 = s.top();
				s.pop();

				int val1 = s.top();
				s.pop();

				char op = ops.top();
				ops.pop();

				s.push(applyOp(val1, val2, op));
			}

			ops.push(exp[i]);
		}
	}

	while(!ops.empty())
	{
		int val2 = s.top();
		s.pop();

		int val1 = s.top();
		s.pop();

		char op = ops.top();
		ops.pop();

		s.push(applyOp(val1, val2, op));
	}

	return s.top();
}

156. Tree Isomorphism Problem

bool isIsomorphic(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;

	return a->data == b->data && (isIsomorphic(a->left, b->right) && isIsomorphic(a->right, b->left)) || (isIsomorphic(a->left, b->left) && isIsomorphic(a->right, b->right));
}

157. Arrange given numbers to form the biggest number

bool compare(string X, string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);

	return XY.compare(YX) > 0; 
}

void arrange(vector<string> arr)
{
	sort(arr.begin(), arr.end(), compare);

	for(int i = 0; i < arr.size(); i++)
		printf("%s", arr[i]);
}

158. Find the first circular tour that visits all petrol pumps

int gasStation(int gas[], int cost[], int n)
{
	int surplus = 0;
	int deficit = 0;
	int start = 0;

	for(int i = 0; i < n; i++)
	{
		surplus += gas[i] - cost[i];
		if(surplus < 0)
		{
			deficit += (-surplus);
			surplus = 0;
			start = i + 1;
		}
	}

	if(surplus - deficit >= 0)
		return start;
	else
		return -1;
}

159. Divide two integers without using multiplication, division and mod operator

void divide(int numerator, int denominator)
{
	int sign = 1;
	if((numerator < 0) ^ (denominator < 0))
		sign = -1;

	numerator = abs(numerator);
	denominator = abs(denominator);

	int quotient = 0;
	while(numerator >= denominator)
	{
		numerator -= denominator;
		quotient++;
	}

	int remainder = numerator;
	printf("%d %d", quotient * sign, remainder);
}

160. String containing first letter of every word in a given string with spaces

string firstLetterWord(string str)
{
	bool space = true;
	string dest = "";

	for(int i = 0; str[i]; i++)
	{
		if(str[i] == ' ')
			space = true;
		else
		{
			if(space == true)
			{
				dest += str[i];
				space = false;
			}
		}
	}

	return dest;
}

161. Remove BST keys outside the given range

struct node* removeBSTKeys(struct node* root, int min, int max)
{
	if(root == NULL)
		return NULL;

	root->left = removeBSTKeys(root->left, min, max);
	root->right = removeBSTKeys(root->right, min, max);

	if(root->data < min)
	{
		struct node* rChild = root->right;
		free(root);
		return rChild;
	}
	else if(root->data > max)
	{
		struct node* lChild = root->left;
		free(root);
		return lChild;
	}
	else
		return root;
}

162. Square root

int sqrt(int input)
{
	if(input == 0 || input == 1)
		return input;

	int ans = -1;
	int low = 1, high = input / 2;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		int midsqr = mid * mid;

		if(midsqr == input)
			return mid;
		else if(midsqr < input)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return ans;
}

163. Find a pair with given sum in BST

void pairSumBST(struct node* root, int sum, unordered_set<int>& hash)
{
	if(root == NULL)
		return;

	pairSumBST(root->left, sum, hash);

	if(hash.find(sum - root->data) != hash.end())
	{
		printf("%d %d", root->data, sum - root->data);
		return;
	}

	pairSumBST(root->right, sum, hash);
}

164. Pairwise swap adjacent nodes of a linked list by changing pointers

void pairwiseSwap(struct node** head)
{
	struct node* prev = NULL;
	struct node* first = *head;

	while(first != NULL && first->next != NULL)
	{
		struct node* second = first->next;
		first->next = second->next;
		second->next = first;

		if(prev == NULL)
			*head = second;
		else
			prev->next = second;

		prev = first;
		first = first->next;
	}
}

165. Difference between sums of odd level and even level nodes of a Binary tree

int diffSumOdd(struct node* root)
{
	if(root == NULL)
		return -1;

	queue<struct node*> q;
	q.push(root);

	int oddSum = 0, evenSum = 0;
	bool odd = true;

	while(1)
	{
		int n = q.size();

		if(n == 0)
			break;

		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();

			if(odd)
				oddSum += temp->data;
			else
				evenSum += temp->data;

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}

		odd = !odd;
	}

	return abs(oddSum - evenSum);
}

166. Write your own atoi()

int myAtoi(string str)
{
	int sign = 1;

	int i = 0;
	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}

	int result = 0;
	for(; str[i]; i++)
		result = result * 10 + (str[i] - '0')

	return result * sign;
}

167. Swap Kth node from beginning with Kth node from end in a Linked List

void swapKth(struct node** head, int k)
{
	if(*head == NULL)
		return;
	
	int n = count(*head);

	if(k > n)
		return;
	if(2 * k - 1 == n)
		return;

	struct node* xprev = NULL;
	struct node* x = *head;
	for(int i = 1; i <= k - 1 && x != NULL; i++)
	{
		xprev = x;
		x = x ->next;
	}

	struct node* yprev = NULL;
	struct node* y = *head;
	for(int i = 1; i <= n - k && y != NULL; i++)
	{
		yprev = y;
		y = y->next;
	}

	if(xprev != NULL)
		xprev->next = y;
	if(yprev != NULL)
		yprev->next = x;

	struct node* temp = x->next;
	x->next = y->next;
	y->next = temp;

	if(k == 1)
		*head = y;
	if(k == n)
		*head = x;
}

168. Find minimum number of coins that make a given value

int minCoins(int coins[], int amount, int n)
{
	int DP[n + 1][amount + 1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= amount; j++)
		{
			if(i == 0)
				DP[i][j] = INT_MAX;
			else if(j == 0)
				DP[i][j] = 0;
			else if(i == 1)
			{
				if(j % coins[i - 1] == 0)
					DP[i][j] = j / coins[i - 1];
				else
					DP[i][j] = DP[i - 1][j];
			}
			else if(coins[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = min(DP[i - 1][j], 1 + DP[i][j - coins[i - 1]]);
		}
	}

	return DP[n][amount];
}

169. Sort a linked list of 0s, 1s and 2s

void sort012(struct node* head)
{
	struct node* rider = head;
	int count[3] = {0};
	while(rider != NULL)
	{
		count[rider->data]++;
		rider = rider->next;
	}

	rider = head;
	int i = 0;
	while(rider != NULL)
	{
		if(count[i] == 0)
			i++;
		else
		{
			rider->data = i;
			count[i]--;
			rider = rider->next;
		}
	}
}

170. Find next greater number with same set of digits

void nextGreater(int num[], int n)
{
	for(int i = n - 2; i >= 0; i--)
	{
		if(num[i] < num[i + 1])
			break;
	}

	int smallest = i;
	int greater = i + 1;
	for(int j = i + 2; j < n; j++)
	{
		if(num[j] > num[smallest] && num[j] < num[greater])
			greater = j;
	}

	swap(&num[smallest], &num[greater]);
	reverse(num + smallest + 1, num + n);
}


171. Print Ancestors of a given node in Binary Tree

void printAncestors(struct node* root, int k, int path[], int index)
{
	if(root == NULL)
		return;

	path[index++] = root->data;

	if(root->data == k)
	{
		for(int i = 0; i < index - 1; i++)
			printf("%d", path[i]);
		return;
	}

	printAncestors(root->left, k, path, index);
	printAncestors(root->right, k, path, index);
}

172. Snake and Ladder Problem

struct queue_struct
{
	int x;
	int count;
};

int minDiceThrows(int N, vector<int> moves)
{
	vector<int> visited(N + 1, 0);

	queue<queue_struct> q;
	q.push({1, 0});
	visited[1] = 1;

	while(!q.empty())
	{
		queue_struct U = q.front();
		q.pop();

		int u = U.x;
		int count = U.count;

		if(u == N)
			return count;

		for(int v = u + 1; v <= u + 6 && v <= N; v++)
		{
			if(!visited[v])
			{
				visited[v] = 1;

				int next_v = v;
				if(moves[v] != -1)
					next_v = moves[v];
			
				q.push({next_v, count + 1});
			}
		}
	}
}

173. Find if there is a path between two vertices in a directed graph

bool isPath(int N, vector<int>* adj, int src, int dest)
{
	if(src == dest)
		return true;

	vector<int> visited(N, 0);

	queue<int> q;
	q.push(src);
	visited[src] = 1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		if(u == dest)
			return true;

		for(auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = *it;
			if(!visited[v])
			{
				visited[v] = 1;
				q.push(v);
			}
		}
	}

	return false;
}

174. Profession in a special family

char profession(int level, int pos)
{
	int c = countSetBits(pos - 1);
	return c % 2 ? 'D' : 'E';
}

175. Print all combinations of balanced parantheses

void printCombinations(string str, int open, int close)
{
	if(open > close)
		return;

	if(open == 0 && close == 0)
	{
		cout << str;
		return;
	}

	if(open > 0)
		printCombinations(str + "(", open - 1, close);
	if(close > 0)
		printCombinations(str + ")", open, close - 1);
}

176. Find position of an element in a sorted array of infinite numbers

int posInfinite(int a[], int key)
{
	int low = 0, high = 1;
	while(key > a[high])
	{
		low = high;
		high = 2 * high;
	}

	return binSearch(a, low, high, key);
}

177. Maximum profit after buying and selling the stocks any number of times

int maxProfit(int a[], int n)
{
	int max_profit = 0;

	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[i - 1])
			max_profit += a[i] - a[i - 1];
	}

	return max_profit;
}

178. Subset Sum Problem

bool subsetSum(int a[], int n, int sum)
{
	bool DP[n + 1][sum + 1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			if(i == 0)
				DP[i][j] = false;
			else if(j == 0)
				DP[i][j] = true;
			else if(a[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] || DP[i - 1][j - a[i - 1]];
		}
	}

	return DP[n][sum];
}

179. Convert a BST to a Binary Tree such that sum of all greater keys is added to every key

void sumGreaterBT(struct node* root, int* sum)
{
	if(root == NULL)
		return;

	sumGreaterBT(root->right, sum);

	*sum += root->data;
	root->data = *sum;
	
	sumGreaterBT(root->left, sum);
}

180. The Stock Span Problem

void stockSpan(int a[], int n)
{
	int S[n];
	S[0] = 1;

	stack<int> s;
	s.push(0);

	for(int i = 1; i < n; i++)
	{
		while(!s.empty() && a[i] >= a[s.top()])
			s.pop();

		S[i] = s.empty() ? i + 1 : i - s.top();

		s.push(i);
	}

	for(int i = 0; i < n; i++)
		printf("%d", S[i]);
}

181. Check if two BSTs contain same set of elements

void storeInorder(struct node* root, vector<int>& v)
{
	if(root == NULL)
		return;

	storeInorder(root->left, v);

	v.push_back(root->data);

	storeInorder(root->right, v);
}

bool isSame(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;

	vector<int> v1;
	storeInorder(a, v1);

	vector<int> v2;
	storeInorder(b, v2);

	return v1 == v2;
}

182. Check if a word exists in a grid or not

int row[4] = {-1, 0, 0, 1};
int col[4] = {0, -1, 1, 0};

bool isSafe(int x, int y, int i, string word, vector<vector<char>> M, int m, int n)
{
	return x >= 0 && x < m && y >= 0 && y < n && M[x][y] == word[i];
}

bool searchWordUtil(int x, int y, int i, string word, vector<vector<char>> M, int m, int n)
{
	if(i == word.size() - 1)
		return true;

	char temp = M[x][y];
	M[x][y] = '#';

	for(int k = 0; k < 4; k++)
	{
		int next_x = x + row[k];
		int next_y = y + col[k];

		if(isSafe(next_x, next_y, i + 1, word, M, m, n))
		{
			if(searchWordUtil(next_x, next_y, i + 1, word, M, m, n))
				return true;
		}
	}

	M[x][y] = temp;
	return false;
}

bool searchWord(string word, vector<vector<char>> M)
{
	int m = M.size();
	int n = M[0].size();

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; i++)
		{
			if(M[i][j] == word[0])
			{
				if(searchWordUtil(i, j, 0, word, M, m, n))
					return true;
			}
		}
	}

	return false;
}

183. K Closest Points to Origin

struct Point
{
	int x, y;
};

int dist(Point p)
{
	return p.x * p.x + p.y * p.y;
}

int partition(Point a[], int low, int high)
{
	int i = low - 1;
	Point pivot = a[high];

	for(int j = low; j <= high - 1; j++)
	{
		if(dist(a[j]) <= dist(pivot))
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	i++;
	swap(&a[i], &a[high]);
	return i;
}

int randomPartition(Point a[], int low, int high)
{
	srand(time(NULL));
	int n = high - low + 1;
	int pivot = rand() % n;
	swap(&a[low + pivot], &a[high]);
	return partition(a, low, high);
}

int quick_select(Point a[], int low, int high, int k)
{
	if(low == high && low == k - 1)
		return low;

	if(low < high)
	{
		int p = randomPartition(a, low, high);
		if(k - 1 == p)
			return p;
		else if(k - 1 < p)
			return quick_select(a, low, p - 1, k);
		else
			return quick_select(a, p + 1, high, k);
	}
}

void kClosestPoints(Point a[], int n, int k)
{
	quick_select(a, 0, n - 1, k);

	for(int i = 0; i < k; i++)
		printf("%d %d", a[i].x, a[i].y);
}

184. Maximize number of 0s by flipping a subarray

int countZeros(int a[], int n)
{
	int zero = 0;

	int curr_sum = 0, max_so_far = 0;

	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
			zero++;

		int val = (a[i] == 0) ? -1 : 1;
		curr_sum = max(curr_sum + val, val);
		max_so_far = max(max_so_far, curr_sum);
	}

	return max_so_far + zero;
}

185. Infix to Postfix

string infixToPostfix(string infix)
{
	string postfix = "";
	stack<char> ops;

	for(int i = 0; infix[i]; i++)
	{
		if(isdigit(infix[i]))
			postfix += infix[i];
		else if(infix[i] == '(')
			ops.push(infix[i]);
		else if(infix[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				postfix += ops.top();
				ops.pop();
			}

			ops.pop();
		}
		else
		{
			while(!ops.empty() && prcd(ops.top()) >= prcd(infix[i]))
			{
				postfix += ops.top();
				ops.pop();
			}

			ops.push(infix[i]);
		}
	}

	while(!ops.empty())
	{
		postfix += ops.top();
		ops.pop();
	}

	return postfix;
}

186. Print all permutations with repetition of characters

void printPermutationsUtil(string str, string data)
{
	if(data.size() == str.size())
		cout << data << endl;
	else
	{
		for(int i = 0; str[i]; i++)
			printPermutationsUtil(str, data + str[i]);
	}
}

void printPermutations(string str)
{
	sort(str.begin(), str.end());
	printPermutationsUtil(str, "");
}

187. Check if a matrix is a scalar matrix

bool isScalar(int M[][], int n)
{
	int element = M[0][0];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j && M[i][j] != element)
				return false;
			if(i != j && M[i][j] != 0)
				return false;
		}
	}

	return true;
}

188. Reverse Level Order Traversal

void reverseLevelOrder(struct node* root)
{
	if(root == NULL)
		return;

	queue<struct node*> q;
	q.push(root);

	stack<struct node*> s;

	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();

		s.push(temp);

		if(temp->right)
			q.push(temp->right);
		if(temp->left)
			q.push(temp->left);
	}

	while(!s.empty())
	{
		printf("%d", s.top()->data);
		s.pop();
	}
}

189. Top K Frequent Elements 

void swap(pair<int, int>* a, pair<int, int>* b)
{
	pair<int, int> temp = *a;
    *a = *b;
    *b = temp;
}

int partition(pair<int, int> a[], int low, int high)
{
    pair<int, int> pivot = a[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++)
    {
        if(a[j].second > pivot.second)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    i++;
    swap(&a[i], &a[high]);
    return i;
}

int randomPartition(pair<int, int> a[], int low, int high)
{
    srand(time(NULL));
    int n = high - low + 1;
    int pivot = rand() % n;
    swap(&a[low + pivot], &a[high]);
    return partition(a, low, high); 
}

int quick_select(pair<int, int> a[], int low, int high, int k)
{
    if(low == high && low == k - 1)
	    return low;

    if(low < high)
    {
        int p = randomPartition(a, low, high);
        if(k - 1 == p)
            return p;
        else if(k - 1 < p)
            return quick_select(a, low, p - 1, k);
        else
            return quick_select(a, p + 1, high, k);
    }
}
    
vector<int> topKFrequent(vector<int> nums, int k) 
{
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++)
        hash[nums[i]]++;
    
    int n = hash.size();
    pair<int, int> a[n];
    int index = 0;
    for(auto it = hash.begin(); it != hash.end(); it++)
        a[index++] = make_pair(it->first, it->second);
    
    quick_select(a, 0, n - 1, k);
    
    vector<int> result;
    for(int i = 0; i < k; i++)
        result.push_back(a[i].first);
    
    return result;
}

190. Count words in a given string

int countWords(char* str)
{
	bool space = true;
	int count = 0;

	for(int i = 0; str[i]; i++)
	{
		if(str[i] == '  ')
			space = true;
		else
		{
			if(space == true)
			{
				count++;
				space = false;
			}
		}
	}

	return count;
}

191. Reduce number to a single digit by subtracting adjacent digits repeatedly

int reduceToSingle(int num)
{
	while(num >= 10)
	{
		int n = num;

		vector<int> a;
		while(n > 0)
		{
			a.push_back(n % 10);
			n = n / 10;
		}
		reverse(a.begin(), a.end());

		n = 0;
		for(int i = 0; i < a.size() - 1; i++)
			n = n * 10 + abs(a[i] - a[i + 1]);

		num = n;
	}

	return num;
}

192. Print Right View of a Binary Tree

void rightView(struct node* root)
{
	if(root == NULL)
		return;

	queue<struct node*> q;
	q.push(root);

	while(1)
	{
		int n = q.size();

		if(n == 0)
			break;

		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();

			if(i == n)
				printf("%d", temp->data);

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

193. Most frequent element in an array

void mostFrequent(int a[], int n)
{
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++)
		hash[a[i]]++;

	int max_count = INT_MIN;
	int res = -1;
	for(auto it = hash.begin(); it != hash.end(); it++)
	{
		if(it->second > max_count)
		{
			max_count = it->second;
			res = it->first;
		}
	}

	return res;
}

194. Print a Binary Tree in Vertical Order

void printVertical(struct node* root)
{
	if(root == NULL)
		return;

	unordered_map<int, vector<int>> hash;
	queue<pair<struct node*, int>> q;
	q.push({root, 0});

	while(!q.empty())
	{
		pair<struct node*, int> temp_pair = q.front();
		q.pop();

		struct node* temp = temp_pair.first;
		int hd = temp_pair.second;

		hash[hd].push_back(temp->data);

		if(temp->left)
			q.push({temp->left, hd - 1});
		if(temp->right)
			q.push({temp->right, hd + 1});
	}

	for(auto it = hash.begin(); it != hash.end(); it++)
	{
		for(int i = 0; i < it->second.size(); it++)
			printf("%d", it->second[i]);
		printf("\n");
	}
}

195. Topological Sort

//A topological sort of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering

void topologicalSortUtil(int u, int N, vector<int>* adj, vector<int>& visited, stack<int>& s)
{
	visited[u] = 1;

	for(auto it = adj[u].begin; it != adj[u].end(); it++)
	{
		int v = *it;

		if(!visited[v])
			topologicalSortUtil(v, N, adj, visited, s);
	}

	s.push(u);
}

void topologicalSort(int N, vector<int>* adj)
{
	vector<int> visited(N, 0);
	stack<int> s;

	for(int i = 0; i < N; i++)
	{
		if(!visited[i])
			topologicalSortUtil(i, N, adj, visited, s);
	}

	while(!s.empty())
	{
		printf("%d", s.top());
		s.pop();
	}
}

196. Generate n-bit Gray Codes

void generateGrayCodes(int n)
{
	vector<string> arr;
	arr.push_back("0");
	arr.push_back("1");

	for(int i = 2; i < (1 << n); i = 2 * i)
	{
		for(int j = i - 1; j >= 0; j--)
			arr.push_back(arr[j]);

		for(int j = 0; j < i; j++)
			arr[j] = "0" + arr[j];

		for(int j = i; j < 2 * i; j++)
			arr[j] = "1" + arr[j]; 
	}

	for(int i = 0; i < arr.size(); i++)
		cout << arr[i];
}

197. Maximum sum rectangle in a 2D matrix

int kadane(int a[], int n, int* top, int* bottom)
{
	int curr_sum = 0;
	int max_so_far = INT_MIN;
	int current_top = 0;

	*bottom = -1;

	for(int i = 0; i < n; i++)
	{
		curr_sum += a[i];

		if(curr_sum < 0)
		{
			current_top = i + 1;
			curr_sum = 0;
		}
		else if(curr_sum > max_so_far)
		{
			max_so_far = curr_sum;
			*top = current_top;
			*bottom = i;
		}
	}

	if(*bottom != -1)
		return max_so_far;
	else
	{
		max_so_far = INT_MIN;
		for(int i = 0; i < n; i++)
		{
			if(a[i] > max_so_far)
			{
				max_so_far = a[i];
				*top = i;
				*bottom = i;
			}
		}
		return max_so_far;
	}
}

void maxSumRectangle(int M[][], int m, int n)
{
	int top = 0, bottom = 0;
	int sum;
	int maxSum = INT_MIN, maxLeft, maxRight, maxTop, maxBottom;

	for(int L = 0; L < n; L++)
	{
		int temp[m] = {0};

		for(int R = L; R < n; R++)
		{
			for(int i = 0; i < m; i++)
				temp[i] += M[i][R];

			sum = kadane(temp, m, &top, &bottom);

			if(sum > maxSum)
			{
				maxSum = sum;
				maxTop = top;
				maxBottom = bottom;
				maxLeft = L;
				maxRight = R;
			}
		}
	}

	printf("%d %d %d %d", maxTop, maxBottom, maxLeft, maxRight);
	printf("%d", maxSum);
}

Time complexity - O(n*n*m)
Space complexity - O(m)

198. Convert decimal number to binary number

string decimalToBinary(double decimal, int kprec)
{
	string binary = "";

	int integral = decimal;
	double fractional = decimal - integral;

	while(integral > 0)
	{
		binary += to_string(integral % 2);
		integral /= 2;
	}
	reverse(binary.begin(), binary.end);
	binary += "."

	while(kprec--)
	{
		fractional *= 2;
		int num = fractional;
		binary += to_string(num);
		fractional -= num;
	}

	return binary;
}

199. Print maximum sum square sub-matrix of given size

void maxSumSquare(int M[][], int n, int k)
{
	int DP[n][n];

	DP[0][0] = M[0][0];

	for(int j = 1; j < n; j++)
		DP[0][j] = DP[0][j - 1] + M[0][j];

	for(int i = 1; i < n; i++)
		DP[i][0] = DP[i - 1][0] + M[i][0];

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] + M[i][j] - DP[i - 1][j - 1];
		}
	}

	int maxSum = INT_MIN, max_i, max_j;

	for(int i = k - 1; i < n; i++)
	{
		for(int j = k - 1; j < n; j++)
		{
			int total = DP[i][j];

			if(i - k >= 0)
				total -= DP[i - k][j];
			if(j - k >= 0)
				total -= DP[i][j - k];
			if(i - k >= 0 && j - k >= 0)
				total += DP[i - k][j - k];

			if(total > maxSum)
			{
				maxSum = total;
				max_i = i;
				max_j = j;
			}
		}
	}

	for(int i = max_i - k + 1; i <= max_i; i++)
	{
		for(int j = max_j - k + 1; j <= max_j; j++)
		{
			printf("%d", M[i][j]);
		}
	}
}

200. Find Shortest distance from a guard in a Bank

int row[4] = {-1, 0, 0, 1};
int col[4] = {0, -1, 1, 0};

struct queue_struct
{
	int x;
	int y;
	int count;
};

bool isSafe(int x, int y, vector<vector<char>> M, int m, int n, vector<vector<int>> output)
{
	return x >= 0 && x < m && y >= 0 && y < n && M[x][y] == 'O' && output[x][y] == -1;
}

void shortestDistance(vector<vector<char>> M)
{
	int m = M.size();
	int n = M[0].size();

	queue<queue_struct> q;

	vector<vector<int>> output(m, vector<int>(n, -1));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(M[i][j] == 'G')
			{
				q.push({i, j, 0});
				output[i][j] = 0;
			}
		}
	}

	while(!q.empty())
	{
		queue_struct U = q.front();
		q.pop();

		int x = U.x;
		int y = U.y;
		int count = U.count;

		for(int k = 0; k < 4; k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];

			if(isSafe(next_x, next_y, M, m, n, output))
			{
				output[next_x][next_y] = count + 1;
				q.push({next_x, next_y, count + 1});
			}
		}
	}
}

201. Check if all leaves are at same level

bool areLeavesSameLevel(struct node* root)
{
	if(root == NULL)
		return true;

	queue<struct node*> q;
	q.push(root);
	int level = 0;
	int result = INT_MIN;

	while(1)
	{
		int n = q.size();
		level++;

		if(n == 0)
			break;

		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();

			if(temp->left == NULL && temp->right == NULL)
			{
				if(result == INT_MIN)
					result = level;
				else
				{
					if(result != level)
						return false;
				}
			}

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}

	return true;
}

202. Zigzag (or diagonal) traversal of Matrix

void zigZag(int M[][], int m, int n)
{
	for(int k = 0; k < m; k++)
	{
		int i = k;
		int j = 0;

		while(i >= 0 && j < n)
		{
			printf("%d", M[i][j]);
			i--;
			j++;
		}
	}

	for(int k = 1; k < n; k++)
	{
		int i = m - 1;
		int j = k;

		while(i >= 0 && j < n)
		{
			printf("%d", M[i][j]);
			i--;
			j++;
		}
	}
}

203. Merge sort

void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];
	int i, j, k;

	for(i = 0; i < n1; i++)
		L[i] = a[l + i];

	for(j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	i = 0, j = 0, k = l;

	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}

	while(i < n1)
		a[k++] = L[i++];

	while(j < n2)
		a[k++] = R[j++];
}

void merge_sort(int a[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

204. Construct Complete Binary Tree from its Linked List Representation

struct Tnode* LL_to_BT(struct Lnode* head)
{
	if(head == NULL)
		return NULL;

	queue<struct Tnode*> q;

	struct Tnode* root = newNode(head->data);
	head = head->next;
	q.push(root);

	while(head != NULL)
	{
		struct Tnode* parent = q.front();
		q.pop();

		struct Tnode* leftChild = newNode(head->data);
		head = head->next;
		q.push(leftChild);
		parent->left = leftChild;

		if(head != NULL)
		{
			struct Tnode* rightChild = newNode(head->data);
			head = head->next;
			q.push(rightChild);
			parent->right = rightChild;
		}
	}

	return root;
}

205. Merge Overlapping Intervals

bool compare(Interval i1, Interval i2)
{
	return i1.start < i2.start;
}

vector<Interval> mergeOverlappingIntervals(vector<Interval> a)
{
	sort(a.begin(), a.end(), compare);

	vector<Interval> result;
	result.push_back(a[0]);

	for(int i = 1; i < a.size(); i++)
	{
		if(a[i].start > result[result.size() - 1].end)
			result.push_back(a[i]);
		else
			result[result.size() - 1].end = max(result[result.size() - 1].end, a[i].end);
	}

	return result;
}

206. Sort a nearly sorted(or K sorted) array

void sortKSorted(int a[], int n)
{
	priority_queue<int, vector<int>, greater<int>> min_heap;

	for(int i = 0; i < k + 1; i++)
		min_heap.push(a[i]);

	int index = 0;
	for(; i < n; i++)
	{
		a[index++] = min_heap.top();
		min_heap.pop();

		min_heap.push(a[i]);
	}

	while(!min_heap.empty())
	{
		a[index++] = min_heap.top();
		min_heap.pop();
	}
}

Time complexity = O(n log k)
Space complexity = O(k)

207. Count ways to reach the nth stair

int countStairs(int n)
{
	int DP[n + 1];
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;

	for(int i = 3; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];

	return DP[n];
}

208. Find first positions of an element in a sorted array

int firstOcc(int a[], int n, int key)
{
	int first = -1;
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
		{
			first = mid;
			high = mid - 1;
		}
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return first;
}

209. Find the only missing number in a sorted array (You are given a sorted array of N integers from 1 to N)

int missing_number(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;

		if(a[mid] == mid + 1)
			low = mid + 1;
		else
		{
			if(low == mid || a[mid - 1] == mid)
				return mid + 1;
			else
				high = mid - 1;
		}
	}

	return n + 1;
}

Time complexity = O(log n)

210. Largest Rectangular Area in a Histogram

int largestRectangle(int a[], int n)
{
	stack<int> s;
	int area, max_area = INT_MIN;

	int i = 0; 
	while(i < n)
	{
		if(s.empty() || a[i] > a[s.top()])
		{
			s.push(i);
			i++;
		}
		else
		{
			int tp = s.top();
			s.pop();

			area = a[tp] * (s.empty() ? i : i - 1 - s.top());

			if(area > max_area)
				max_area = area;
		}
	}

	while(!s.empty())
	{
		int tp = s.top();
		s.pop();

		area = a[tp] * (s.empty() ? i : i - 1 - s.top());

		if(area > max_area)
			max_area = area;
	}

	return max_area;
}

211. String matching where one string contains wildcard characters

bool isMatch(char* str, char* pattern)
{
	int m = strlen(str);
	int n = strlen(pattern);

	bool DP[m + 1][n + 1];
	memset(DP, false, sizeof(DP));

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 && j == 0)
				DP[i][j] = true;
			else if(i == 0 && pattern[j - 1] == "*")
				DP[i][j] = DP[i][j - 1];
			else if(str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
				DP[i][j] = DP[i - 1][j - 1];
			else if(pattern[j - 1] == '*')
				DP[i][j] = DP[i][j - 1] || DP[i - 1][j];
			else
				DP[i][j] = false;
		}
	}

	return DP[m][n];
}

212. Find if two rectangles overlap
l1: Top Left coordinate of first rectangle.
r1: Bottom Right coordinate of first rectangle.
l2: Top Left coordinate of second rectangle.
r2: Bottom Right coordinate of second rectangle.

bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
	if(l2.x >= r1.x || l1.x >= r2.x)
		return false;
	if(r2.y >= l1.y || r1.y >= l2.y)
		return false;
	return true;
}

213. Calculate the angle between hour hand and minute hand

/*
Hour hand:
12 hours 	-> 360
12 * 60 min -> 360
1 min 		-> 0.5

Minute Hand
60 min 	-> 360
1 min 	-> 6
*/
int angle(int h, int m)
{
	if(h == 12)
		h = 0;
	if(m == 60)
		m = 0;

	int angle_made_by_hh = 0.5 * (h * 60 + m);
	int angle_made_by_mh = 6 * m;

	int diff = abs(angle_made_by_hh - angle_made_by_mh);

	return min(diff, 360 - diff);
}

214. Find largest subtree sum in a tree

int largestSubtree(struct node* root, int* maxSum)
{
	if(root == NULL)
		return 0;

	int ls = largestSubtree(root->left, maxSum);
	int rs = largestSubtree(root->right, maxSum);

	int curr_sum = ls + rs + root->data;
	if(curr_sum > *maxSum)
		*maxSum = curr_sum;
	return curr_sum;
}

215. Rearrange positive and negative numbers in O(n) time and O(1) extra space (alternatively)

void rearrange(int a[], int n)
{
	int i = -1; 
	for(int j = 0; j < n; j++)
	{
		if(a[j] < 0)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}

	int neg = 0, pos = i + 1;
	while(neg < pos && pos < n && a[neg] < 0)
	{
		swap(&a[neg], &a[pos]);
		neg += 2;
		pos++;
	}
}

216. Given a sorted dictionary of an alien language, find order of characters

void topologicalSortUtil(int u, vector<int> adj[26], vector<int>& visited, stack<int>& s)
{
	visited[u] = 1;

	for(auto it = adj[u].begin(); it != adj[u].end(); it++)
	{
		int v = *it;

		if(!visited[v])
			topologicalSortUtil(v, adj, visited, s);
	}

	s.push(u);
}

void topologicalSort(vector<int> adj[26])
{
	stack<int> s;
	vector<int> visited(26, 0);

	for(int i = 0; i < 26; i++)
	{
		if(!visited[i])
			topologicalSortUtil(i, adj, visited, s);
	}

	while(!s.empty())
	{
		cout << s.top() + 'a';
		s.pop();
	}
}

void alienDictionary(vector<string> dictionary)
{
	vector<int> adj[26];

	for(int i = 0; i < dictionary.size() - 1; i++)
	{
		string first = dictionary[i];
		string second = dictionary[i + 1];

		for(int j = 0; first[j] && second[j]; j++)
		{
			if(first[j] != second[j])
			{
				adj[first[j] - 'a'].push_back(second[j] - 'a');
				break;
			}
		}
	}

	topologicalSort(adj);
}

217. Find minimum difference between any two elements

int minDiff(int a[], int n)
{
	sort(a, a + n);

	int min_diff = INT_MAX;
	for(int i = 1; i < n; i++)
	{
		if(a[i] - a[i - 1] < min_diff)
			min_diff = a[i] - a[i - 1];
	}

	return min_diff;
}

218. Trapping Rain Water

int trappingRainWater(int a[], int n)
{
	int LMax[n];
	LMax[0] = a[0];
	for(int i = 1; i < n; i++)
		LMax[i] = max(LMax[i - 1], a[i]);

	int RMax[n];
	RMax[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--)
		RMax[i] = max(RMax[i + 1], a[i]);

	int water = 0;
	for(int i = 0; i < n; i++)
		water += min(LMax[i], RMax[i]) - a[i];

	return water;
}

219. Partition a set into two subsets such that the difference of subset sums is minimum

int partitionMinSum(int a[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];

	bool DP[n + 1][sum + 1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			if(i == 0)
				DP[i][j] = false;
			else if(j == 0)
				DP[i][j] = true;
			else if(a[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] || DP[i - 1][j - a[i - 1]];
		}
	}

	int min_diff;
	for(int j = sum / 2; j >= 0; j--)
	{
		if(DP[n][j])
		{
			min_diff = sum - 2 * j;
			break;
		}
	}

	return min_diff;
}

220. Nuts & Bolts Problem

void nutsBolts(char nuts[], char bolts[], int n)
{
	unordered_set<char> hash;

	for(int i = 0; i < n; i++)
		hash.insert(nuts[i]);

	for(int i = 0; i < n; i++)
	{
		if(hash.find(bolts[i]) != hash.end())
			nuts[i] = bolts[i];
	}

	for(int i = 0; i < n; i++)
		printf("%c", nuts[i]);

	for(int i = 0; i < n; i++)
		printf("%c", bolts[i]);
}
 
221. Check whether a binary tree is a full binary tree or not

bool isFullBinaryTree(struct node* root)
{
	if(root == NULL || root->left == NULL && root->right == NULL)
		return true;
	else if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
		return false;
	else
		return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
}

222. Find K Largest elements

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++)
	{
		if(a[j] > pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	i++;
	swap(&a[i], &a[j]);
	return i;
}

int randomPartition(int a[], int low, int high)
{
	srand(time(NULL));
	int n = high - low + 1;
	int pivot = rand() % n;
	swap(&a[low + pivot], &a[high]);
	return partition(a, low, high); 
}

void quick_select(int a[], int low, int high, int k)
{
	if(low == high && low == k - 1)
		return low;

	if(low < high)
	{
		int p = randomPartition(a, low, high);
		if(k - 1 == p)
			return p;
		else if(k - 1 < p)
			return quick_select(a, low, p - 1, k);
		else
			return quick_select(a, p + 1, high, k);
	}
}

void kLargestElements(int a[], int n, int k)
{
	quick_select(a, 0, n - 1, k);

	for(int i = 0; i < k; i++)
		printf("%d", a[i]);
}

223. Word Break Problem

bool word_break(string str, unordered_set<string> dictionary)
{
	int n = str.length();
	
	bool DP[n + 1];	
	memset(DP, false, sizeof(DP));	

	DP[0] = true;
	for(int i = 0; i < n; i++)
	{
		if(DP[i] == true)
		{
			for(int j = i + 1; j <= n; j++)
			{
				string temp = str.substr(i, j - i);
				if(dictionary.find(temp) != dictionary.end())
					DP[j] = true;
			}
		}
	}

	return DP[n];
}

224. Remove duplicates from an array of small primes

void removeDuplicates(vector<int> a)
{
	unordered_set<int> hash(a.begin(), a.end());
	a.assign(hash.begin(), hash.end());
}

225. Find the closest element in Binary Search Tree

void closestElement(struct node* root, int k, int* minNode, int* minDiff)
{
	if(root == NULL)
		return;

	if(k == root->data)
	{
		*minDiff = 0;
		*minNode = root->data;
		return;
	}

	if(abs(k - root->data) < *minDiff)
	{
		*minDiff = abs(k - root->data);
		*minNode = root->data;
	}

	if(k < root->data) //BST
		closestElement(root->left, k, minNode, minDiff);
	else
		closestElement(root->right, k, minNode, minDiff);
}

226. Maximum path sum that starting with any cell of 0-th row and ending with any cell of (N-1)-th row
There are only three possible moves from a cell (i, j)
(i+1, j)
(i+1, j-1)
(i+1, j+1)

int maxPathSum(int M[][], int m, int n)
{
	for(int i = 1; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(j - 1 >= 0 && j + 1 < n)
				M[i][j] += max(M[i - 1][j - 1], M[i - 1][j], M[i - 1][j + 1]);
			else if(j - 1 >= 0)
				M[i][j] += max(M[i - 1][j - 1], M[i - 1][j]);
			else if(j + 1 < n)
				M[i][j] += max(M[i - 1][j], M[i - 1][j + 1]);
		}
	}

	int res = INT_MIN;
	for(int j = 0; j < n; j++)
		res = max(res, M[m - 1][j]);

	return res;
}

227. Minimum insertions to form a palindrome

int minInsertions(char* X)
{
	char Y[30];
	strcpy(Y, X);
	strrev(Y);
	return strlen(X) - LCS(X, Y);
}

228. Longest Common Substring

int longestCommonSubstring(char* X, char* Y)
{
	int m = strlen(X);
	int n = strlen(Y);

	int DP[m + 1][n + 1];

	int result = INT_MIN;
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
				DP[i][j] = 0;
			else if(X[i - 1] == Y[j - 1])
			{
				DP[i][j] = 1 + DP[i - 1][j - 1];
				result = max(result, DP[i][j]);
			}
			else
				DP[i][j] = 0;
		}
	}

	return result;
}

229. Rotate a matrix by 90 degree in clockwise direction without using any extra space

void transpose(int M[][], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			swap(&M[i][j], &M[j][i]);
		}
	}
}

void reverseRows(int M[][], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0, k = n - 1; j < k; j++, k--)
		{
			swap(&M[i][j], &M[i][k]);
		}
	}
}

void rotate(int M[][], int n)
{
	transpose(M, n);
	reverseRows(M, n);
}

230. Count all possible paths from top left to bottom right of a mXn matrix

int nCr(int n, int r)
{
	int result = 1;

	for(int i = 0; i < r; i++)
	{
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

int possiblePaths(int m, int n)
{
	return nCr(m + n - 2, m - 1);
}

231. Remove all nodes which dont lie in any path with sum >= k

struct node* prune(struct node* root, int k, int sum)
{
	if(root == NULL)
		return NULL;

	sum += root->data;

	root->left = prune(root->left, k, sum);
	root->right = prune(root->right, k, sum);

	if(root->left == NULL && root->right == NULL)
	{
		if(sum < k)
		{
			free(root);
			return NULL;
		}
	}

	return root;
}

232. Print Left View of a Binary Tree

void leftView(struct node* root)
{
	if(root == NULL)
		return;

	queue<struct node*> q;
	q.push(root);

	while(1)
	{
		int n = q.size();

		if(n == 0)
			break;

		for(int i = 1; i <= n; i++)
		{
			struct node* temp = q.front();
			q.pop();

			if(i == 1)
				printf("%d", temp->data);

			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

233. Extract Leaves of a Binary Tree in a Doubly Linked List

struct node* extractLeaves(struct node* root, struct node** head)
{
	if(root == NULL)
		return NULL;

	if(root->left == NULL && root->right == NULL)
	{
		root->right = *head;
		if((*head) != NULL)
			(*head)->left = root;
		*head = root;
		return NULL;
	}

	root->right = extractLeaves(root->right, head);
	root->left = extractLeaves(root->left, head);
	return root;
}

//Tricks:
//1. leaf deletion should always be preorder, if postorder, all nodes will be deleted
//2. if deletion, signature is struct node*

234. Find a peak element

int peakElement(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		if(low == high)
			return a[low];
		else if(high == low + 1)
			return a[low] > a[high] ? a[low] : a[high];
		else
		{
			int mid = low + (high - low) / 2;
			if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
				return a[mid];
			else if(a[mid] < a[mid - 1])
				high = mid - 1;
			else if(a[mid] < a[mid + 1])
				low = mid + 1;
		}
	}

	return -1;
}

235. Dice Throw

int diceThrow(int n, int m, int sum)
{
	int DP[n + 1][sum + 1] = {0};

	for(int j = 1; j <= sum && j <= m; j++)
		DP[1][j] = 1;

	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			for(int k = 1; k <= m && k <= j; k++)
			{
				DP[i][j] += DP[i - 1][j - k];
			}
		}
	}

	return DP[n][sum]; 
}

236. Optimal Strategy for a Game

int optimalStrategy(int a[], int n)
{
	int DP[n][n];

	for(int i = 0; i < n; i++)
		DP[i][i] = a[i];

	for(int i = 0; i < n - 1; i++)
		DP[i][i + 1] = max(a[i], a[i + 1]);

	for(int L = 3; L <= n; L++)
	{
		for(int i = 0; i < n - L + 1; i++)
		{
			int j = i + L - 1;

			DP[i][j] = max(a[i] + min(DP[i + 2][j], DP[i + 1][j - 1]),
						   a[j] + min(DP[i][j - 2], DP[i + 1][j - 1]));
		}
	}

	return DP[0][n - 1];
}

// calculate coins at even and odd places and compare, if even > odd, take even 

237. Find the longest substring with k unique characters in a given string

int longestSubstring(char* str, int k)
{
	unordered_map<char, int> hash;
	int max_len = INT_MIN;

	int begin = 0;
	for(int end = 0; str[end]; end++)
	{
		hash[str[end]]++;

		if(hash.size() == k)
			max_len = max(max_len, end - begin + 1);
		else
		{
			while(hash.size() > k)
			{
				hash[str[begin]]--;

				if(hash[str[begin]] == 0)
					hash.erase(str[begin]);
				
				begin++;
			}
		}
	}

	return max_len;
}

238. Delete N nodes after M nodes of a linked list

void skipMdelN(struct node* head, int m, int n)
{
	while(head != NULL)
	{
		for(int i = 1; i <= m - 1 && head != NULL; i++)
			head = head->next;

		if(head == NULL)
			return;

		struct node* rider = head->next;
		for(int i = 1; i <= n && rider != NULL; i++)
		{
			struct node* r_next = rider->next;
			free(rider);
			rider = r_next;
		}

		head->next = rider;
		head = rider;
	}
}

239. Find the minimum distance between two numbers

int minDiff(int a[], int n, int x, int y)
{
	int prev;

	int i;
	for(i = 0; i < n; i++)
	{
		if(a[i] == x || a[i] == y)
		{
			prev = i;
			break;
		}
	}

	int min_dist = INT_MAX;
	for(; i < n; i++)
	{
		if(a[i] == x || a[i] == y)
		{
			if(a[prev] != a[i])
				min_dist = min(min_dist, i - prev);
			
			prev = i;
		}
	}

	return min_dist;
}

240. Auto-complete feature using Trie 

struct node
{
	struct node* children[26];
	bool isEnd;
};

void autoCompleteUtil(struct node* root, string str)
{
	if(root == NULL)
		return;

	if(root->isEnd == true)
		printf("%s", str);

	for(int i = 0; i < 26; i++)
	{
		if(root->children[i] != NULL)
			autoCompleteUtil(root->children[i], str + (i + 'a'));
	}
}

void autoComplete(struct node* root, string str)
{
	for(int i = 0; str[i]; i++)
	{
		int index = str[i] - 'a';
		if(root->children[index] == NULL)
			return;
		root = root->children[index1];
	}

	return autoCompleteUtil(root, str);
}

241. Longest Zig-Zag Subsequence

int sigNum(int num)
{
	if(num == 0)
		return 0;
	else if(num > 0)
		return 1;
	else
		return -1;
}

int wiggle(int a[], int n)
{
	if(n == 0)
		return 0;

	int lastSign = 0, len = 1;

	for(int i = 0; i < n - 1; i++)
	{
		int sign = sigNum(a[i] - a[i + 1]);

		if(sign != 0 && sign != lastSign)
		{
			len++;
			lastSign = sign;
		}
	}

	return len;
}

242. Check if given Sudoku board configuration is valid or not

bool isValidRow(char grid[9][9], int row)
{
	unordered_set<char> hash;

	for(int col = 0; col < 9; col++)
	{
		if(grid[row][col] != '-')
		{
			if(grid[row][col] < '1' || grid[row][col] > '9')
				return false;

			if(hash.find(grid[row][col]) != hash.end())
				return false;
			else
				hash.insert(grid[row][col]);
		}
	}

	return true;
}

bool isValidCol(char grid[9][9], int col)
{
	unordered_set<char> hash;

	for(int row = 0; row < 9; row++)
	{
		if(grid[row][col] != '-')
		{
			if(grid[row][col] < '1' || grid[row][col] > '9')
				return false;

			if(hash.find(grid[row][col]) != hash.end())
				return false;
			else
				hash.insert(grid[row][col]);
		}
	}

	return true;
}

bool isValidSquare(char grid[9][9])
{
	for(int row = 0; row < 9; row += 3)
	{
		for(int col = 0; col < 9; col += 3)
		{
			unordered_set<char> hash;

			for(int i = row; i < row + 3; i++)
			{
				for(int j = col; j < col + 3; j++)
				{
					if(grid[i][j] != '-')
					{
						if(grid[i][j] < '1' || grid[i][j] > '9')
							return false;

						if(hash.find(grid[i][j]) != hash.end())
							return false;
						else
							hash.insert(grid[i][j]);
					}
				}
			}
		}
	}
	return true;
}

bool isValidSudoku(char grid[9][9])
{
	for(int i = 0; i < 9; i++)
	{
		if(!isValidRow(grid, i))
			return false;
		if(!isValidCol(grid, i))
			return false;
	}

	return isValidSquare(grid);
}

243. Egg Dropping Puzzle

int eggDrop(int n, int k)
{
	int DP[n + 1][k + 1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			if(i == 0 || j == 0)
				DP[i][j] = 0;
			else if(i == 1)
				DP[i][j] = j;
			else if(j == 1)
				DP[i][j] = 1;
			else
			{
				DP[i][j] = INT_MAX
				for(int x = 1; x <= j; x++)
				{
					int temp = max(1 + DP[i - 1][x - 1], 1 + DP[i][j - x]);
					DP[i][j] = min(DP[i][j], temp);
				}
			}
		}
	}

	return DP[n][k];
}

244. Given a Binary Tree. Assuming each node denotes some x,y coordinate. Assume root node denotes (0,0). Write a code to display coordinate of all nodes.

void displayCoordinate(struct node* root, int x, int y)
{
	if(root == NULL)
		return;

	printf("%d %d", x, y)
	displayCoordinate(root->left, x - 1, y - 1);
	displayCoordinate(root->right, x + 1, y - 1);
}

245. Design a data structure that supports insert, delete, search and getRandom in constant time

class DS
{
	vector<int> a;
	unordered_map<int, int> hash;
public:
	void insert(int element)
	{
		if(hash.find(element) != hash.end())
			return;

		a.push_back(element);
		hash[element] = a.size() - 1;
	}

	void delete(int element)
	{
		if(hash.find(element) == hash.end())
			return;

		int index = hash[element];
		swap(&a[index], &a[a.size() - 1]);
		hash[a[index]] = index;

		a.pop_back();
		hash.erase(element);
	}

	int search(int element)
	{
		if(hash.find(element) == hash.end())
			return;
		return hash[element];
	}

	int getRandom()
	{
		srand(time(NULL));
		int n = a.size();
		return a[rand() % n];
	}
};

246. Check if an array can be divided into pairs whose sum is divisible by k

bool canDivide(int a[], int n, int k)
{
	if(n % 2 != 0)
		return false;

	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++)
		hash[a[i] % k]++;

	for(int i = 0; i < n; i++)
	{
		int rem = a[i] % k;
		if(rem == 0)
		{
			if(hash[rem] % 2 != 0)
				return false;
		}
		else if(2 * rem == k)
		{
			if(hash[rem] % 2 != 0)
				return false;
		}
		else
		{
			if(hash[rem] != hash[k - rem])
				return false;
		}
	}

	return true;
}

247. Merge a linked list into another linked list at alternate positions

void mergeAlternate(struct node* a, struct node* b)
{
	while(a != NULL && b != NULL)
	{
		struct node* a_next = a->next;
		struct node* b_next = b->next;

		a->next = b;
		b->next = a_next;

		a = a_next;
		b = b_next;
	}
}

248. Print Postorder traversal from given Inorder and Preorder traversals

void printPostorder(int in[], int pre[], int inS, int inE, int preS, int preE)
{
	if(inS > inE)
		return;

	int rootData = pre[preS];
	int rootIndex = -1;
	for(int i = inS; i <= inE; i++)
	{
		if(rootData == in[i])
		{
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int rInS = rootIndex + 1;
	int rInE = inE;

	int lPreS = preS + 1;
	int lPreE = lPreS + lInE - lInS;
	int rPreS = lPreE + 1;
	int rPreE = preE;

	printPostorder(in, pre, lInS, lInE, lPreS, lPreE);	
	printPostorder(in, pre, rInS, rInE, rPreS, rPreE);
	printf("%d", rootData);
}

249. Word Ladder (Length of shortest chain to reach a target word)

struct queue_struct
{
	string word;
	int count;
}

int wordLadder(string start, string target, unordered_set<string>& hash)
{
	if(start.compare(target) == 0)
		return 0;

	queue<queue_struct> q;
	q.push({start, 0});

	while(!q.empty())
	{
		queue_struct U = q.front();
		q.pop();

		string word = U.word;
		int count = U.count;

		if(word.compare(target) == 0)
			return count;

		for(int i = 0; word[i]; i++)
		{
			char org = word[i];
			for(int j = 0; j < 26; j++)
			{
				word[i] = j + 'a';
				if(hash.find(word) != hash.end())
				{
					q.push({word, count + 1});
					hash.erase(word);
				}
			}
			word[i] = org;
		}
	}

	return -1;
}

250. Minimum steps to reach target by a Knight

struct queue_struct
{
	int x;
	int y;
	int count;
};

int N;
int visited[20][20];

int row[8] = {-2, -1, -1, -2, 2, 1, 1, 2};
int col[8] = {-1, -2, 1, 2, -1, -2, 2, 1};

bool isSafe(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N && !visited[x][y]; 
}

int minStepsKnight(int src_x, int src_y, int dest_x, int dest_y)
{

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			visited[i][j] = 0;
		}
	}

	queue<queue_struct> q;
	q.push({src_x, src_y, 0});
	visited[src_x][src_y] = 1;

	while(!q.empty())
	{
		queue_struct U = q.front();
		q.pop();

		int x = U.x;
		int y = U.y;
		int count = U.count;

		if(x == dest_x && y == dest_y)
			return count;

		for(int k = 0; k < 8; k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];

			if(isSafe(next_x, next_y))
			{
				visited[next_x][next_y] = 1;
				q.push({next_x, next_y, count + 1});
			}
		}
	}

	return -1;
}

251. Count Possible Decodings of a given Digit Sequence

int countDecodings(char* str)
{
	int n = strlen(str);
	int DP[n + 1];

	DP[0] = 1;
	DP[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		DP[i] = 0;

		if(str[i - 1] > '0')
			DP[i] += DP[i - 1];

		if(str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] <= '6'))
			DP[i] += DP[i - 2];
	}

	return DP[n];
}

252. Floor and Ceil from a BST

void floorCeil(struct node* root, int k, struct node** floor, struct node** ceil)
{
	while(root != NULL)
	{
		if(k == root->data)
		{
			*floor = root;
			*ceil = root;
			break;
		}
		else if(k < root->data)
		{
			*ceil = root;
			root = root->left;
		}
		else
		{
			*floor = root;
			root = root->right;
		}
	}
}

253. Deletion from a Circular Linked List

void delNode(struct node** head, int data)
{
	if((*head) == NULL)
		return;

	if((*head)->data == data)
	{
		if((*head)->next == *head)
		{
			free((*head));
			*head = NULL;
		}
		else
		{
			struct node* rider = *head;
			while(rider->next != *head)
				rider = rider->next;
			rider->next = (*head)->next;
			free((*head));
			*head = rider->next;
		}
	}
	else
	{
		struct node* rider = *head;
		while(rider->next != *head && rider->next->data != data)
			rider = rider->next;
		struct node* temp = rider->next;
		rider->next = temp->next;
		free(temp);
	}
}

254. Check divisibility in a binary stream

/*
m = nq + r
2m = 2nq + 2r
2m % n = 2r % n

m = nq + r
2m + 1 = 2nq + 2r + 1
(2m + 1) % n = (2r + 1) % n
*/

void divisibility(int n)
{
	int incoming_bit;
	int remainder = 0;

	while(true)
	{
		scanf("%d", &incoming_bit);

		if(incoming_bit == 0)
			remainder = (2 * remainder) % n;
		else if(incoming_bit == 1)
			remainder = (2 * remainder + 1) % n;
		else
			break;

		if(remainder % n == 0)
			printf("Divisible");
		else
			printf("Not Divisible");
	}
}

255. Remove all leaf nodes from the binary search tree

struct node* removeLeafNodes(struct node* root)
{
	if(root == NULL)
		return NULL;

	if(root->left == NULL && root->right == NULL)
	{
		free(root);
		return NULL;
	}

	root->left = removeLeafNodes(root->left);
	root->right = removeLeafNodes(root->right);

	return root;
}

256. Sieve of Eratosthenes

void sieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	for(int i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			//instead of starting from i, optimization is to start from i * i, because lower than that would hv already been marked false
			for(int j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}

	for(int i = 0; i <= n; i++)
	{
		if(prime[i])
			printf("%d", i);
	}

}

257. Shortest path in a Binary Maze

int row[4] = {-1, 0, 0, 1};
int col[4] = {0, -1, 1, 0};

struct queue_struct
{
	int x;
	int y;
	int count;
};

bool isSafe(int x, int y, vector<vector<int>> M, int m, int n, vector<vector<int>> visited)
{
	return x >= 0 && x < m && y >= 0 && y < n && M[x][y] && !visited[x][y];
}

int shortestPath(vector<vector<int>> M, int src_x, int src_y, int dest_x, int dest_y)
{
	int m = M.size();
	int n = M[0].size();

	vector<vector<int>> visited(m, vector<int>(n, 0));

	queue<queue_struct> q;
	q.push({src_x, src_y, 0});
	visited[src_x][src_y] = 1;

	while(!q.empty())
	{
		queue_struct U = q.front();
		q.pop();

		int x = U.x;
		int y = U.y;
		int count = U.count;

		if(x == dest_x && y == dest_y)
			return count;

		for(int k = 0; k < 4; k++)
		{
			int next_x = x + row[k];
			int next_y = y + col[k];

			if(isSafe(next_x, next_y, M, m, n, visited))
			{
				q.push({next_x, next_y, count + 1});
				visited[next_x][next_y] = 1;
			}
		}
	}
}

258. Check whether the length of given linked list is Even or Odd

void evenOddList(struct node* head)
{
	while(head != NULL && head->next != NULL)
		head = head->next->next;

	if(head)
		printf("Odd");
	else
		printf("Even");
}

259. Find the length of largest subarray with 0 sum

int subarray0(int a[], int n)
{
	int max_len = 0;
	int curr_sum = 0;
	unordered_map<int, int> hash;

	for(int i = 0; i < n; i++)
	{
		curr_sum += a[i];

		if(curr_sum == 0)
			max_len = i + 1;

		if(hash.find(curr_sum) != hash.end())
			max_len = max(max_len, i - hash[curr_sum]);
		else
			hash[curr_sum] = i;
	}

	return max_len;
}

260. Sort a string according to the order defined by another string

void sortString(char* str, char* pat)
{
	int count[256];
	memset(count, 0, sizeof(count));

	for(int i = 0; str[i]; i++)
		count[str[i]]++;

	int index = 0;
	for(int i = 0; pat[i]; i++)
	{
		for(int j = 0; j < count[pat[i]]; j++)
			str[index++] = pat[i];
	}
	str[index] = '\0';
}

261. Sum of all the numbers that are formed from root to leaf paths

void sumNumbers(struct node* root, int num, int* sum)
{
	if(root == NULL)
		return;

	num = num * 10 + root->data;

	if(root->left == NULL && root->right == NULL)
	{
		*sum += num;
		return;
	}

	sumNumbers(root->left, num, sum);
	sumNumbers(root->right, num, sum);
}

262. Reverse alternate K nodes in a Singly Linked List

struct node* reverseListKAlternate(struct node* head, int k)
{
	struct node* rider = head;
	struct node* r_next = NULL;
	struct node* prev = NULL;
	int count = 0;

	while(rider != NULL && count < k)
	{
		r_next = rider->next;
		rider->next = prev;
		prev = rider;
		rider = r_next;
		count++;
	}

	head->next = rider;

	for(int i = 1; i <= k - 1 && rider != NULL; i++)
		rider = rider->next;

	if(rider != NULL && rider->next != NULL)
		rider->next = reverseListKAlternate(rider->next, k);

	return prev;
}

263. Maximum profit by buying and selling a share at most once

int maxProfit(int a[], int n)
{
	int max_profit = INT_MIN;
	int min_element = INT_MAX;

	for(int i = 0; i < n; i++)
	{
		if(a[i] < min_element)
			min_element = a[i];
		if(a[i] - min_element > max_profit)
			max_profit = a[i] - min_element;
	}

	return max_profit;
}

264. Search an element in an array where difference between adjacent elements is 1

int search(int a[], int n, int key)
{
	int i = 0;
	while(i < n)
	{
		if(a[i] == key)
			return i;
		i += abs(a[i] - key);
	}

	return -1;
}

265. Queue based approach for first non-repeating character in a stream

void getFirstNonRepeating(char* str)
{
	queue<char> q;
	int count[256];
	memset(count, 0, sizeof(count));

	for(int i = 0; str[i]; i++)
	{
		q.push(str[i]);
		count[str[i]]++;

		while(!q.empty() && count[q.front()] > 1)
			q.pop();

		if(!q.empty())
			printf("%c", q.front());
		else
			printf("-1");
	}
}

266. Detect cycle in an undirected graph

//path by compression
int find(int x, int parent[], int rank[])
{
	if(x != parent[x])
		parent[x] = find(parent[x], parent, rank);

	return parent[x];
}

//union by rank
void Union(int x, int y, int parent[], int rank[])
{
	int x1 = find(x, parent, rank);
	int y1 = find(y, parent, rank);

	if(rank[x1] > rank[y1])
		parent[y1] = x1;
	else if(rank[y1] > rank[x1])
		parent[x1] = y1;
	else
	{
		parent[x1] = y1;
		rank[y1]++;
	}
}

bool cycle(int N, int E, int E1[], int E2[])
{
	int parent[N + 1];
	int rank[N + 1];

	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	for(int i = 1; i <= E; i++)
	{
		int x = find(E1[i], parent, rank);
		int y = find(E2[i], parent, rank);

		if(x == y)
			return true;
		else
			Union(x, y, parent, rank);
	}

	return false;
}

//doubt???
Time complexity = O(V)
Each find and union is alpha(V) -> growing function cant be more than 4

267. Move all zeroes to end of array

void moveZero(int a[], int n)
{
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] != 0)
			a[j++] = a[i];
	}

	while(j < n)
		a[j++] = 0;
}

268. Modify a binary tree to get preorder traversal using right pointers only

void modifyBinaryTree(struct node* root)
{
	if(root == NULL)
		return;

	stack<struct node*> s;
	s.push(root);
	struct node* prev = NULL;

	while(!s.empty())
	{
		struct node* temp = s.top();
		s.pop();

		if(prev != NULL)
		{
			prev->left = NULL;
			prev->right = temp;
		}
		prev = temp;

		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}

269. Count 1’s in a sorted non-increasing binary array

int last1(int a[], int n)
{
	int last = -1;
	int low = 0, high = n - 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(a[mid] == 1)
		{
			last = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return last + 1;
}

270. Implement two stacks in an array

class Stacks
{
	int size;
	int* arr;
	int top1;
	int top2;
public:
	Stacks(int n)
	{
		size = n;
		arr = new int[size];
		top1 = -1;
		top2 = size;
	}

	void push1(int element)
	{
		if(top1 < top2 - 1)
			a[++top1] = element;
		else
			printf("Overflow");
	}

	int top1()
	{
		if(top1 > -1)
		{
			int element = a[top1--];
			return element;
		}
		else
		{
			printf("Underflow");
			return -1;
		}
	}

	void push2(int element)
	{
		if(top1 < top2 - 1)
			a[--top2] = element;
		else
			printf("Overflow");
	}

	int top2()
	{
		if(top2 < size)
		{
			int element = a[top2++];
			return element;
		}
		else
		{
			printf("Underflow");
			return -1;
		}
	}
};

271. Maximum and minimum of an array using minimum number of comparisons

struct minmax
{
	int min;
	int max;
};

struct minmax getMinMax(int a[], int low, int high)
{
	struct minmax result;

	if(low == high)
	{
		result.min = a[low];
		result.max = a[high];
	}
	else if(high == low + 1)
	{
		if(a[low] > a[high])
		{
			result.min = a[high];
			result.max = a[low];
		}
		else
		{
			result.min = a[low];
			result.max = a[high];
		}
	}
	else
	{
		int mid = low + (high - low) / 2;
		struct minmax mml = getMinMax(a, low, mid);
		struct minmax mmr = getMinMax(a, mid + 1, high);

		if(mml.min < mmr.min)
			result.min = mml.min;
		else
			result.min = mmr.min;

		if(mml.max > mmr.max)
			result.max = mml.max;
		else
			result.max = mmr.max;
	}

	return result;
}

No of comparisons = 
3n/2 - 2, if n is a power of 2
Little more than 3n/2 - 2, if n is not a power of 2

//2(n - 1) - n/2 = 2n - 2 - n/2 = 3n/2 - 2 
//https://www.quora.com/How-does-the-tournament-method-for-finding-the-maximum-and-minimum-element-in-an-array-consist-of-3n-2-2-comparisons

272. Find the maximum repeating number in O(n) time and O(1) extra space. (contains numbers in range from 0 to k-1 where k is a positive integer and k <= n)

int getMaximum(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int index = a[i] % n;
		a[index] += n;
	}

	int max_element = INT_MIN;
	int max_i;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > max_element)
		{
			max_element = a[i];
			max_i = i;
		}
	}

	return max_i;
}

273. Find an element in Bitonic array

int findPivot(int a[], int n)
{
	int low = 0, high = n - 1;
	while(low <= high)
	{
		if(low == high)
			return low;
		else if(high == low + 1)
			return a[low] > a[high] ? low : high;
		else
		{
			int mid = low + (high - low) / 2;
			if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
				return mid;
			else if(a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
				low = mid + 1;
			else if(a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
				high = mid - 1;
		}
	}

	return -1;
}

int aBinSearch(int a[], int low, int high, int key)
{
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

int dBinSearch(int a[], int low, int high, int key)
{
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return -1;
}

int element_bitonic(int a[], int n, int key)
{
	int p = findPivot(a, n);

	if(key > a[p])
		return -1;
	else if(key >= a[0] && key <= a[p])
		return aBinSearch(a, 0, p, key);
	else
		return dBinSearch(a, p + 1, n - 1, key);
}

274. Binary Search Tree | Set 1 (Search and Insertion)

struct node* insert(struct node* root, int key)
{
	if(root == NULL)
	{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->data = key;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	if(key < root->data)
		root->left = insert(root->left, key);
	else if(key > root->data)
		root->right = insert(root->right, key);

	return root;
}

bool search(struct node* root, int key)
{
	while(root != NULL)
	{
		if(key == root->data)
			return true;
		else if(key < root->data)
			root = root->left;
		else
			root = root->right;
	}

	return false;
}

275. Binary Search Tree | Set 2 (Delete)

struct node* delete(struct node* root, int key)
{
	if(root == NULL)
		return NULL;

	if(root->data == key)
	{
		if(root->left == NULL)
		{
			struct node* rightChild = root->right;
			free(root);
			return rightChild;
		}
		else if(root->right == NULL)
		{
			struct node* leftChild = root->left;
			free(root);
			return leftChild;
		}
		else if(root->left != NULL && root->right != NULL)
		{
			struct node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	else if(key < root->data)
		root->left = delete(root->left, key);
	else
		root->right = delete(root->right, key);

	return root;
}

276. Check if two trees are Mirror

bool areMirror(struct node* a, struct node* b)
{
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;
	
	return a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

277. Count all possible groups of size 2 or 3 that have sum as multiple of 3

int countGroups(int a[], int n)
{
	int C[3] = {0};

	for(int i = 0; i < n; i++)
		C[a[i] % 3]++;

	int result = 0;
	result += (C[0] * C[0] - 1) / 2;
	result += C[1] * C[2];

	result += (C[0] * C[0] - 1 * C[0] - 2) / 6;
	result += (C[1] * C[1] - 1 * C[1] - 2) / 6;
	result += (C[2] * C[2] - 1 * C[2] - 2) / 6;
	result += C[0] * C[1] * C[2];

	return result;
}

278. Given two strings, find if first string is a subsequence of second

bool isSubsequence(char* str1, char* str2, int m, int n)
{
	if(m == 0)
		return true;
	if(n == 0)
		return false;

	if(str1[m - 1] == str2[n - 1])
		return isSubsequence(str1, str2, m - 1, n - 1);
	else
		return isSubsequence(str1, str2, m, n - 1);
}

279. Design a hit counter which counts the number of hits received in the past 5 minutes.

class HitCounter
{
	int timestamps[300];
	int count[300];
public:
	void hit(int timestamp)
	{
		int index = timestamp % 300;
		if(timestamps[index] < timestamp)
		{
			timestamps[index] = timestamp;
			count[index] = 1;
		}
		else
			count[index]++;
	}

	int getHitCounts(int timestamp)
	{
		int total = 0;
		for(int i = 0; i < 300; i++)
		{
			if(timestamp - timestamps[i] < 300)
				total += count[i];
		}
		return total;
	}
}

280. Reverse alternate levels of a perfect binary tree

void reverseAlternate(struct node* root)
{
	if(root == NULL)
		return;

	queue<struct node*> q;
	q.push(root);

	stack<int> s;
	int leftToRight = 1;

	while(1)
	{
		int n = q.size();

		if(n == 0)
			break;

		if(leftToRight)
		{
			for(int i = 1; i <= n; i++)
			{
				struct node* temp = q.front();
				q.pop();

				if(temp->left)
				{
					q.push_back(temp->left);
					s.push(temp->left->data);
				}
				if(temp->right)
				{
					q.push_back(temp->right);
					s.push(temp->right->data);
				}
			}
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				struct node* temp = q.front();
				q.pop();

				temp->data = s.top();
				s.pop();

				if(temp->left)
					q.push_back(temp->left);
				if(temp->right)
					q.push_back(temp->right);
				
			}
		}

		leftToRight = !leftToRight;
	}
}

348. Median of two sorted arrays with different sizes

double median(int a[], int aLen, int b[], int bLen)
{
	if(aLen > bLen)
		return median(b, bLen, a, aLen);

	int leftHalfLen = (aLen + bLen + 1) / 2;

	int low = 0;
	int high = aLen;

	while(low <= high)
	{
		int aCount = low + (high - low) / 2;
		int bCount = leftHalfLen - aCount;

		int x = (aCount == 0) ? INT_MIN : a[aCount - 1];
		int y = (bCount == 0) ? INT_MIN : b[bCount - 1];

		int xP = (aCount == aLen) ? INT_MAX : a[aCount];
		int yP = (bCount == bLen) ? INT_MAX : b[bCount];

		if(x <= yP && y <= xP)
		{
			if((aLen + bLen % 2) != 0)
				return max(x, y);
			else
				return max(x, y) + min(xP, yP) / 2.0;
		}
		else if(x > yP)
			high = aCount - 1;
		else if(y > xP)
			low = aCount + 1;
	}

	return -1;
}

349. Maximum circular subarray sum

int maxSubarraySumCircular(int* a, int n)
{
    int max_so_far = a[0];
    int min_so_far = a[0];
    int curr_sum = a[0];
    int curr_max = a[0];
    int curr_min = a[0];
    
    for(int i = 1; i < n; i++)
    {
        curr_sum += a[i];
        
        curr_max = max(curr_max + a[i], a[i]);
        curr_min = min(curr_min + a[i], a[i]);
        
        max_so_far = max(max_so_far, curr_max);
        min_so_far = min(min_so_far, curr_min);
    }
    
    //first condition -> if all elements are -ve	
    return curr_sum == min_so_far ? max_so_far : max(max_so_far, (curr_sum - min_so_far));
}

350. Smallest subarray with sum greater than a given value

int smallestSubarray(int a[], int n, int sum)
{
	int curr_sum = 0;
	int min_len = INT_MAX;

	int begin = 0;
	for(int end = 0; end < n; end++)
	{
		curr_sum += a[end];

		while(curr_sum >= sum)
		{
			min_len = min(min_len, end - begin + 1);
			curr_sum -= a[begin];
			begin++;
		}
	}

	return min_len;
}

351. Position of robot after given movements

Point position(string move)
{
	Point res = {0, 0};
	for(int i = 0; move[i]; i++)
	{
		if(move[i] == 'U')
			res.y++;
		else if(move[i] == 'D')
			res.y--;
		else if(move[i] == 'L')
			res.x--;
		else if(move[i] == 'R')
			res.x++;
	}

	return res;
}

352. Find Recurring Sequence in a Fraction

string fractionToDecimal(int numr, int den)
{
	long numerator = numr;
	long denominator = den;

	string minus = "";
	if((numerator < 0) ^ (denominator < 0))
		minus = "-";

	numerator = abs(numerator);
	denominator  = abs(denominator);

	string integer = to_string(numerator / denominator);

	long remainder = numerator % denominator;
	if(remainder == 0)
		return minus + integer;

	unordered_map<long, int> hash;
	string rec = "";
	int i = 0;
	while(remainder != 0 && hash.find(remainder) == hash.end())
	{
		hash[remainder] = i;

		remainder *= 10;
		rec += to_string(remainder / denominator);
		remainder = remainder % denominator;
		i++;
	}

	if(remainder != 0)
	{
		int pos = hash[remainder];
		string part1 = rec.substr(0, pos);
		string part2 = rec.substr(pos, string::npos);
		rec = part1 + "(" + part2 + ")";
	}

	return minus + integer + "." + rec;
}

353. Program to add two fractions

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

Fraction addFractions(Fraction a, Fraction b)
{
	Fraction result;
	result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	result.denominator = a.denominator * b.denominator;

	int common_factor = gcd(result.numerator, result.denominator);
	result.numerator /= common_factor;
	result.denominator /= common_factor;

	return result;
}

354. Weighted Job Scheduling

bool compare(Job j1, Job j2)
{
	return j1.end < j2.end;
}

int latestNonConflictingJob(Job a[], int index)
{
	int low = 0, high = index - 1;
	int ans = -1;

	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(a[index].start >= a[mid].end)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return ans;
}

int weightedJobScheduling(Job a[], int n)
{
	sort(a, a + n, compare);

	int DP[n];
	DP[0] = a[0].profit;

	for(int i = 1; i < n; i++)
	{
		int l = latestNonConflictingJob(a, i);

		int incl = a[i].profit;
		if(l != -1)
			incl += DP[l];

		DP[i] = max(DP[i - 1], incl);
	}

	return DP[n - 1];
}

355. Form minimum number from given sequence

string minimumNumber(string sequence)
{
	int n = sequence.size() + 1;
	if(n > 9)
		return "not defined";

	string result = "";
	for(int num = 0; num <= n; num++)
		result += to_string(num);

	int i = 1; 
	while(i <= sequence.size())
	{
		int j = i;
		while(i <= sequence.size() && sequence[i - 1] == 'D')
				i++;
		
		reverseArray(result, j, i);
		i++; 
	}

	return result.erase(0, 1);
}

356. Lucky numbers

int isLucky(int pos)
{
	int counter = 2;
	while(pos >= counter)
	{
		if(pos % counter == 0)
			return false;
		pos -= pos / counter;
		counter++;
	}

	return true;
}

357. How to implement a stack which will support following operations in O(1) time complexity?
- push() which adds an element to the top of stack.
- pop() which removes an element from top of stack.
- findMiddle() which will return middle element of the stack.

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

class Stack
{
	struct node* top;
	struct node* mid;
	int count;
public:
	Stack()
	{
		top = NULL;
		mid = NULL;
		count = 0;
	}

	void push(int element)
	{
		struct node* newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = element;
		newnode->prev = NULL;
		newnode->next = top;
		count++;

		if(count == 1)
		{
			top = newnode;
			mid = newnode;
		}
		else
		{
			top->prev = newnode;
			top = newnode;

			if(count % 2 != 0)
				mid = mid->prev;
		}
	}

	int pop()
	{
		if(count == 0)
			return -1;
		else
		{
			struct node* temp = top;
			int result = top->data;
			top = top->next;
			if(top != NULL)
				top->prev = NULL;
			free(temp);

			count--;
			if(count % 2 == 0)
				mid = mid->next;

			return result;
		}
	}
	
	int findMid()
	{
		if(count == 0)
			return -1;
		else
			return mid->data;
	}
};

358. Check if two strings after processing backspace character are equal or not

bool backspaceCompare(string S, string T) 
{
    int i = S.size() - 1;
    int j = T.size() - 1;
        
    int skipS = 0, skipT = 0;
        
    while(i >= 0 || j >= 0)
    {
        while(i >= 0)
        {
            if(S[i] == '#')
            {
                skipS++;
                i--;
            }
            else if(skipS > 0)
            {
                skipS--;
                i--;
            }
            else
                break;
        }
        
        while(j >= 0)
        {
            if(T[j] == '#')
            {
                skipT++;
                j--;
            }
            else if(skipT > 0)
            {
                skipT--;
                j--;
            }
            else
                break;
        }
       
       	/*
       	i != j
       	"ab##"
		"c#d#"
       	*/
        if(i != j && (i < 0 || j < 0))
            return false;
            
        if(i >= 0 && j >= 0 && S[i] != T[j])
            return false;
            
        i--;
        j--;
    }
        
    return true;
} 

359. Minimize Cash Flow among a given set of friends who have borrowed money from each other

void getMaxMinIndex(int a[], int n, int* maxCreditIndex, int* maxDebitIndex)
{
	int max = INT_MIN, min = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
			*maxCreditIndex = i;
		}

		if(a[i] < min)
		{
			min = a[i];
			*maxDebitIndex = i;
		}
	}
}

void minimizeCashFlowUtil(int amount[], int N)
{
	int maxCreditIndex = 0, maxDebitIndex = 0;
	getMaxMinIndex(amount, N, &maxCreditIndex, &maxDebitIndex);

	//settle
	if(amount[maxCreditIndex] == 0 && amount[maxDebitIndex] == 0)
		return;

	int minAmount = min(amount[maxCreditIndex], -amount[maxDebitIndex]);
	amount[maxCreditIndex] -= minAmount;
	amount[maxDebitIndex] += minAmount;

	cout << maxDebitIndex << " will pay " << minAmount << " to " << maxCreditIndex << endl;

	minimizeCashFlowUtil(amount, N);
}

void minimizeCashFlow(int N, int graph[][])
{
	int amount[N];
	memset(amount, 0, sizeof(amount));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			//credit - debit
			amount[i] += graph[j][i] - graph[i][j];
		}
	}

	minimizeCashFlowUtil(amount, N);
}