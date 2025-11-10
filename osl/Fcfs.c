#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void getdata(int n, int proc[], int AT[], int BT[]) {
	for(int i = 0; i < n; i++) {
		proc[i] = i;
		printf("Process P%d:\n", i);
		printf("Arrival Time: ");
		scanf("%d", &AT[i]);
		printf("Burst Time: ");
		scanf("%d", &BT[i]);
	}
}

void displaydata(int n, int proc[], int AT[], int BT[]) {
	printf("\nProcess\tAT\tBT\n");
	for(int i = 0; i < n; i++) {
		printf("P%d\t%d\t%d\n", proc[i], AT[i], BT[i]);
	}
}

void sortbyAT(int n, int proc[], int AT[], int BT[]) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(AT[j] > AT[j + 1]) {
				swap(&AT[j], &AT[j + 1]);
				swap(&BT[j], &BT[j + 1]);
				swap(&proc[j], &proc[j + 1]);
			}
		}
	}
}

void fcfs(int n, int proc[], int AT[], int BT[]) {
	int CT[n], TAT[n], WT[n];
	float total_TAT = 0, total_WT = 0;

	int current_time = AT[0];
	CT[0] = current_time + BT[0];
	current_time = CT[0];

	for(int i = 1; i < n; i++) {
		if(current_time < AT[i]) {
			current_time = AT[i];
		}
		CT[i] = current_time + BT[i];
		current_time = CT[i];
	}

	for(int i = 0; i < n; i++) {
		TAT[i] = CT[i] - AT[i];
		WT[i] = TAT[i] - BT[i];
		total_TAT += TAT[i];
		total_WT += WT[i];
	}

	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i = 0; i < n; i++) {
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", proc[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
	}

	printf("\nGantt Chart:\n|");
	for(int i = 0; i < n; i++) {
		printf(" P%d |", proc[i]);
	}
	printf("\n0");
	for(int i = 0; i < n; i++) {
		printf("   %d", CT[i]);
	}

	printf("\n\nAverage Turnaround Time: %.2f", total_TAT / n);
	printf("\nAverage Waiting Time: %.2f\n", total_WT / n);
}

int main() {
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);

	int proc[n], AT[n], BT[n];

	getdata(n, proc, AT, BT);
	sortbyAT(n, proc, AT, BT);
	displaydata(n, proc, AT, BT);
	fcfs(n, proc, AT, BT);

	return 0;
}
