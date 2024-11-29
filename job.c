/*
 * Replace the following string of 0s with your student number
 * 230408180
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job.h"

/* 
 * DO NOT EDIT the job_new function.
 */
job_t* job_new(pid_t pid, unsigned int id, unsigned int priority, 
    const char* label) {
    return job_set((job_t*) malloc(sizeof(job_t)), pid, id, priority, label);
}

/* 
 * TODO: you must implement this function
 */
job_t* job_copy(job_t* src, job_t* dst) {
    if (src == NULL) {
        return NULL;
    }
    if (src == dst) {
        return dst;
    }
    if (dst == NULL) {
       dst = malloc(sizeof(job_t));
    }
    dst->pid = src->pid;
    dst->id = src->id;
    dst->priority = src->priority;
    strncpy(dst->label,src->label,MAX_NAME_SIZE-1);
    
    return dst;
    }

/* 
 * TODO: you must implement this function
 */
void job_init(job_t* job) {
    if (job != NULL) {
        job->pid = 0;
        job->id = 0;
        job->priority = 0;
        strcpy(job->label, PAD_STRING);
    };
}

/* 
 * TODO: you must implement this function
 */
bool job_is_equal(job_t* j1, job_t* j2) {
    if (j1 == NULL && j2 == NULL) {
        return true;
    }
    
    if (j1 == NULL || j2 == NULL) {
        return false;
    }

    if (j1->pid == j2->pid && j1->id == j2->id && j1->priority == j2->priority && strcmp(j1->label, j2->label) == 0) {
        return true;

    } else {
        return false;
    }
}


/*
 * TODO: you must implement this function.
 * Hint:
 * - read the information in job.h about padding and truncation of job
 *      labels
 */
job_t* job_set(job_t* job, pid_t pid, unsigned int id, unsigned int priority,
    const char* label) {
    if (job == NULL) {
        return NULL;
    }

    job->pid = pid;
    job->id = id;
    job->priority = priority;

    if (label == NULL) {
        memset(job->label, '*', MAX_NAME_SIZE - 1);
    } else {
        if (strlen(label) < MAX_NAME_SIZE) {
            strncpy(job->label, label, strlen(label));
            memset(job->label + strlen(label), '*', MAX_NAME_SIZE - 1 - strlen(label));
        } else {
            strncpy(job->label, label, MAX_NAME_SIZE - 1);
        }
    }
    job->label[MAX_NAME_SIZE - 1] = '\0';

    return job;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see malloc and calloc system library functions for dynamic allocation, 
 *      and the documentation in job.h for when to do dynamic allocation
 */
char* job_to_str(job_t* job, char* str) {
    if (job == NULL) {
        return NULL;
    } else if (str == NULL) {
        str = (char*) malloc(JOB_STR_SIZE * sizeof(char));
    };
    snprintf(str, JOB_STR_SIZE, JOB_STR_FMT,job->pid,job->id,job->priority,job->label);
    return str;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see the hint for job_to_str
 */
job_t* str_to_job(char* str, job_t* job) {
    if (str == NULL)//check if string format is wrong 
    {
        return NULL;
    };
    // need t0 convert the string
    return NULL;
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
    if (job == NULL) {
        return;
    };
    job = NULL; //not sure if this is right
    free(job); //frees up the memeory
    return;
}