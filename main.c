#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CONTENT_LENGTH 1000
#define MAX_TAGS 10
#define MAX_TAG_LENGTH 20

typedef struct {
    char date[11];
    char content[MAX_CONTENT_LENGTH];
    char tags[MAX_TAGS][MAX_TAG_LENGTH];
    int num_tags;
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
} Diary;

void add_entry(Diary *diary, const char *date, const char *content, const char *tags[]) {
    if (diary->num_entries < MAX_ENTRIES) {
        DiaryEntry *entry = &diary->entries[diary->num_entries];
        strncpy(entry->date, date, sizeof(entry->date));
        strncpy(entry->content, content, sizeof(entry->content));
        entry->num_tags = 0;
        for (int i = 0; tags[i] != NULL && i < MAX_TAGS; i++) {
            strncpy(entry->tags[i], tags[i], sizeof(entry->tags[i]));
            entry->num_tags++;
        }
        diary->num_entries++;
    }
}

void search_entries(const Diary *diary, const char *keyword) {
    for (int i = 0; i < diary->num_entries; i++) {
        if (strstr(diary->entries[i].content, keyword) != NULL) {
            printf("%s %s\n", diary->entries[i].date, diary->entries[i].content);
        }
    }
}

void add_tags(Diary *diary, int entry_index, const char *tags[]) {
    if (entry_index >= 0 && entry_index < diary->num_entries) {
        DiaryEntry *entry = &diary->entries[entry_index];
        for (int i = 0; tags[i] != NULL && i < MAX_TAGS; i++) {
            strncpy(entry->tags[entry->num_tags], tags[i], sizeof(entry->tags[entry->num_tags]));
            entry->num_tags++;
        }
    }
}

void save_entries_to_file(const Diary *diary) {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < diary->num_entries; i++) {
        fprintf(file, "Date: %s\n", diary->entries[i].date);
        fprintf(file, "Content: %s\n", diary->entries[i].content);
        fprintf(file, "Tags: ");
        for (int j = 0; j < diary->entries[i].num_tags; j++) {
            fprintf(file, "%s ", diary->entries[i].tags[j]);
        }
        fprintf(file, "\n\n");
    }

    fclose(file);
    printf("Diary entries saved to file.\n");
}

int main() {
    Diary my_diary;
    my_diary.num_entries = 0;

    char date[11];
    char content[MAX_CONTENT_LENGTH];
    char tags[MAX_TAGS][MAX_TAG_LENGTH];
    int num_tags;

    printf("Digite a data (formato: AAAA-MM-DD): ");
    scanf("%s", date);

    printf("Digite o conteúdo: ");
    scanf(" %[^\n]", content);

    printf("Digite o número de tags (até %d): ", MAX_TAGS);
    scanf("%d", &num_tags);

    printf("Digite as tags (separadas por espaço): ");
    for (int i = 0; i < num_tags; i++) {
        scanf("%s", tags[i]);
    }

    add_entry(&my_diary, date, content, (const char**)tags);

    search_entries(&my_diary, "great");

    add_tags(&my_diary, 0, (const char*[]){"positive", NULL});
    for (int i = 0; i < my_diary.entries[0].num_tags; i++) {
        printf("%s\n", my_diary.entries[0].tags[i]);
    }

    save_entries_to_file(&my_diary);

    return 0;
}