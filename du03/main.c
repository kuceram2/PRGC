# include <stdlib.h>
# include <stdio.h>

# define MAX 69
# define MIN 3
# define INPUT_ERR 100
# define RANGE_ERR 101
# define WIDTH_VAL_ERR 102
# define FENCE_SITE_ERR 103

void draw_edge(int width){
    for(int i = 0; i < width; ++i) printf("X");
    printf("\n");
}

void draw_alternating_line(int limit, char odd_ltr, char even_ltr){
    for(int j =0; j < limit; ++j){
        (j % 2) ? printf("%c", odd_ltr) : printf("%c", even_ltr);
    }
}

void draw_simple_house(int width, int height){
    draw_edge(width);
    for(int i = 0; i < (height -2); ++i){
        printf("X");
        for(int j = 0; j < (width -2); ++j) printf(" ");
        printf("X\n");
    }
    draw_edge(width);
}

void draw_fence(int fence, int height, int line){
    if((line == (height-fence-1)) || line == -1){ // if drawing top or bottom line of fence
        if(fence % 2) draw_alternating_line(fence,'-','|'); // if fence size is odd num
        else draw_alternating_line(fence, '|', '-');
    }
    else{
        if(fence % 2) draw_alternating_line(fence, ' ', '|');
        else draw_alternating_line(fence, '|', ' ');
    }
    printf("\n");
}

void draw_house_with_fence(int width, int height, int fence, int new_line){
    int fence_start = height - fence -2;
    draw_edge(width);
    for(int i = 0; i < height -2; ++i){
        printf("X");
        if(i % 2) draw_alternating_line(width-2, 'o', '*'); // for odd lines
        else draw_alternating_line(width-2, '*', 'o');
        
        // if drawing a fence next to the house, dont use "\n"
        (i > fence_start) ? printf("X"): printf("X\n"); 
        if(i > fence_start) draw_fence(fence, height, i);      
    }
    for(int k = 0;  k< width; ++k) printf("X");
    draw_fence(fence, height, -1);

}

void draw_roof(int width){
    int roof_height = (width - 1)/2;
    
    for(int i = 0; i < roof_height; ++i) printf(" ");
    printf("X\n");

    for(int i = 1; i < roof_height; ++i){
        int space_between = (2*i) - 1;
        int space_outside = (width - space_between -2) / 2;
        for(int j = 0; j < space_outside; ++j) printf(" ");
        printf("X");
        for(int j = 0; j < space_between; ++j) printf(" ");
        printf("X\n");
    }

}

void build_house(int width, int height, int fence){
    draw_roof(width);
    if(fence == 0) draw_simple_house(width, height);
    else{
        draw_house_with_fence(width,height,fence, 1);
    }  
}

int is_in_limits(int value){
    if((value >= MIN) & (value <= MAX)) return 1;
    else return 0;
}

int get_input(int *width, int *height, int *fence){
    int temp = -1;
    
    // if reading both values was not succesfull, return err
    if(!(scanf("%d", width) & scanf("%d", height))){
        fprintf(stderr,"Error: Chybny vstup!\n");
        return INPUT_ERR;
    }
    // if at least one of the numbers is out of bounds, return err
    if(!(is_in_limits(*width)) | !is_in_limits(*height)){
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return RANGE_ERR;
    }
    //if width is even number, return err
    if((*width % 2) == 0){
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return WIDTH_VAL_ERR;
    }
    // accepting value for fence
    if(*width == *height){
        if(!(scanf("%d", &temp))){
            fprintf(stderr,"Error: Chybny vstup!\n");
            return INPUT_ERR;
        }

        if((temp > 0) & (temp < *height)) {
            *fence = temp;
        }
        else{
            fprintf(stderr, "Error: Neplatna velikost plotu!\n");
            return FENCE_SITE_ERR;
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
    int width = 0;
    int height = 0;
    int fence = 0;
    int ret = get_input(&width, &height, &fence);
    if(ret) return ret;

    build_house(width, height, fence);
    
    return 0;
}
