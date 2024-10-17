#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    int level;
    struct Node *children[27];
} Node, *Tree;

Node *createNode(char value) {
    int i;
    Node *node = malloc(sizeof(Node));
    node->value = value;
    for (i = 0; i < 27; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void freeTree(Node *root) {
    int i;
    if (!root) {
        return;
    }

    for (i = 0; i < 27; i++) {
        freeTree(root->children[i]);
    }

    free(root);
}

// FUNCTIE INSERARE SUFIXE IN ARBORE
void insertSuffix(Node *root, char *suffix) {
    Node *copy = root;
    int i;
    root->level = 0;
    for (i = 0; suffix[i] != '\0'; i++) {
        int index;
        if (suffix[i] == '$') {
            index = 0;
        } else {
            index = suffix[i] - 'a' + 1;
        }

        if (root->children[index] == NULL) {
            root->children[index] = createNode(suffix[i]);
            root->children[index]->level = root->level + 1;
        }
        if (root->children[index]->value != '$')
            root = root->children[index];
        else
            root = copy;
    }
    root->level = 0;
}

// FUNCTIE AFISARE ARBORE PRINT BREADTH-FIRST SEARCH(BFS)
void afisare(Tree arbore, int n, FILE *Output) {
    Tree *coada = malloc(sizeof(Tree) * n * (n - 1));
    Tree current;
    int i;
    int st = 0, dr = 0;
    int nivel_curent = 1;
    coada[dr++] = arbore;

    while (st < dr) {
        current = coada[st++];
        if (current->level > nivel_curent) {
            nivel_curent = current->level;
            fprintf(Output, "\n");
        }
        if (current != arbore) fprintf(Output, "%c ", current->value);
        for (i = 0; i < 27; i++) {
            if (current->children[i]) {
                coada[dr++] = current->children[i];
            }
        }
    }
    fprintf(Output, "\n");
    free(coada);
}

// FUNCTIE CARE NUMARA CATE NODURI FRUNZA AVEM IN ARBORE
int count_frunza(Node *root) {
    int i, count = 0;
    int cnull = 1;
    // VERFICAM DACA TOTI COPIII SUNT NULI
    for (i = 0; i < 27; i++) {
        if (root->children[i]) {
            cnull = 0;
            break;
        }
    }
    if (cnull) {
        count++;
    }
    // NUMARAM NODURILE SUBARBORELUI RECURSIV
    for (i = 0; i < 27; i++) {
        if (root->children[i]) {
            count = count + count_frunza(root->children[i]);
        }
    }
    return count;
}

// FUNCTIE CARE NUMARA SUFIXELE DE DIMENSIUNE K
int countK(Node *root, int k) {
    int i, count = 0;
    int t = 0;  // contror pentru a stii cate noduri am traversat

    if (root->value == '$' && root->level == k + 1) {
        return 1;
    }
    // PARCURGEM NODURILE COPII RECURSIV
    for (i = 0; i < 27; i++) {
        if (root->children[i]) {
            t++;
            count = count + countK(root->children[i], k);
        }
    }
    if (root->value == '$' && t == k) {
        count++;
    }
    return count;
}

// FUNCTIE CARE INTOARCE VALOARE MAXIMA DE DESCENDENTI DIN NODURILE ARBORELUI
int n_max(Node *root) {
    int i, maxc = 0;  // INITIALIZAM NUMARUL MAXIM DE COPII
    int current = 0;  // SI NUMARUL CURENT DE COPII PE CARE IL ARE UN NOD

    for (i = 0; i < 27; i++) {
        if (root->children[i]) {
            current++;
            if (current > maxc) maxc = current;
            // PUNEM IN MAXC VALOAREA MAXIMA
        }
    }
    return maxc;
}

// FUNCTIE PENTRU VERIFICAREA SUFIXELOR IN ARBORELE NOSTRU
int check(Node *root, char *suffix) {
    int i;
    for (i = 0; suffix[i] != '\0'; i++) {
        int index;
        if (suffix[i] == '$') {
            index = 0;
        } else {
            index = suffix[i] - 'a' + 1;
        }

        if (root->children[index] == NULL) {
            return 0;  // Sufixul nu există
        }

        if (root->children[index]->value != suffix[i]) {
            return 0;  // Sufixul nu coincide cu nodul
        }

        root = root->children[index];
    }

    if (root->children[0] != NULL) {  // Sufix se termină la un nod terminal
        return 1;
    } else {
        return 0;  // Sufixul nu se termină la un nod terminal (nu este complet)
    }
}

int main(int argc, char *argv[]) {
    char *option = argv[1];
    char *inputFile = NULL;
    char *outputFile = NULL;
      int K;

    if (strcmp(option, "-c1") == 0 || strcmp(option, "-c3") == 0 ||
        strcmp(option, "-c4") == 0) {
        inputFile = argv[2];
        outputFile = argv[3];
    } else if(strcmp(option, "-c2") == 0) {
        // Pentru cerinta 2
        K = atoi(argv[2]);
        inputFile = argv[3];
        outputFile = argv[4];
    }
    FILE *Input = fopen(inputFile, "r");
    FILE *Output = fopen(outputFile, "w");
    Node *root = createNode('%');
    int i, j;
    int N,M;
    if (strcmp(option, "-c1") == 0 || strcmp(option, "-c2") == 0 ||
        strcmp(option, "-c4") == 0) {
        fscanf(Input, "%d", &N);
        char text[13][1024];
        for (i = 0; i < N; i++) {
            fscanf(Input, "%s", text[i]);
        }
        int k, nr = 0;
        for (i = 0; i < N; i++) {
            root->level = 0;
            nr = nr + strlen(text[i]);
            // Inserarea sufixelor textului curent în arbore
            for (j = strlen(text[i]); j >= 0; j--) {
                char suffix[1024];
                int suffixLength = 0;

                for (k = j; k < strlen(text[i]); k++) {
                    suffix[suffixLength++] = text[i][k];
                }
                suffix[suffixLength] = '$';
                suffix[suffixLength + 1] = '\0';
                insertSuffix(root, suffix);
            }
        }
        if (strcmp(option, "-c1") == 0) {
            afisare(root, nr, Output);
        } else if (strcmp(option, "-c2") == 0) {
            fprintf(Output, "%d\n", count_frunza(root));
            fprintf(Output, "%d\n", countK(root, K));
            fprintf(Output, "%d\n", n_max(root));
        }
    } else if(strcmp(option, "-c3") == 0) {
        fscanf(Input, "%d %d", &N, &M);
        char text[13][1024];
        int  q;
        for (i = 0; i < N; i++) {
            fscanf(Input, "%s", text[i]);
        }
        char verif[13][1024];
        for (q = 0; q < M; q++) {
            fscanf(Input, "%s", verif[q]);
        }
        int nr = 0;
        unsigned long k;
        for (i = 0; i < N; i++) {
            // Crearea nodului rădăcină
            root->level = 0;
            nr = nr + strlen(text[i]);
            // Inserarea sufixelor textului curent în arbore
            for (j = strlen(text[i]); j >= 0; j--) {
                char suffix[1024];
                int suffixLength = 0;

                for (k = j; k < strlen(text[i]); k++) {
                    suffix[suffixLength++] = text[i][k];
                }
                suffix[suffixLength] = '$';
                suffix[suffixLength + 1] = '\0';
                insertSuffix(root, suffix);
            }
        }
        for (q = 0; q < M; q++) fprintf(Output, "%d\n", check(root, verif[q]));
    
    }

    // Eliberarea memoriei alocate pentru arbore
    freeTree(root);
    fclose(Input);
    fclose(Output);

    return 0;
}