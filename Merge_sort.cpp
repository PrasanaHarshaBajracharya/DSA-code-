# include <iostream>
using namespace std;

void Merge(int arr[], int left , int mid, int right){
    int n1 = mid - left+1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i=0;  i<n1; i++){
        L[i] = arr[left + i];
    }

    for (int i=0;  i<n2; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1){
        arr[k++] = L[i++];
    }

    while (j < n2){
        arr[k++] = R[j++];
    }
}


void MergeSort(int arr[], int left , int right){
    if (left < right){
        int mid = (left + right) / 2;
 
        MergeSort(arr, left, mid);
        MergeSort(arr,mid+1, right);

        Merge(arr, left, mid, right);

    }
}

int main(){
    int array[] = {293, 918, 25, 503, 969, 627, 524, 1000, 650, 267, 323, 251, 806, 915, 170, 865, 872, 856, 
        172, 261, 412, 726, 839, 981, 742, 128, 667, 868, 74, 4, 337, 379, 569, 89, 744, 987, 592, 811, 144, 
        80, 669, 448, 772, 262, 85, 487, 974, 893, 381, 311, 891, 717, 277, 703, 741, 222, 984, 975, 27, 599, 
        274, 632, 175, 486, 390, 6, 964, 437, 126, 738, 159, 87, 674, 578, 399, 889, 362, 508, 706, 953, 923, 
        33, 424, 88, 511, 77, 948, 747, 556, 658, 728, 678, 407, 49, 339, 398, 644, 356, 541, 471, 369, 946, 
        579, 138, 472, 914, 783, 419, 942, 97, 371, 319, 401, 279, 959, 812, 562, 561, 352, 792, 372, 958, 642, 
        849, 977, 154, 660, 921, 970, 259, 146, 473, 376, 614, 980, 612, 807, 797, 951, 428, 265, 189, 926, 112, 
        577, 608, 76, 878, 91, 842, 409, 558, 268, 536, 300, 721, 702, 580, 910, 280, 968, 464, 157, 879, 954, 
        603, 461, 141, 629, 342, 66, 7, 888, 255, 572, 72, 691, 224, 264, 906, 396, 947, 204, 591, 595, 278, 
        875, 635, 999, 492, 621, 786, 354, 547, 911, 594, 24, 636, 404, 896, 965, 845, 96, 467, 95, 699, 512, 
        533, 993, 285, 753, 102, 79, 527, 117, 479, 774, 525, 26, 930, 850, 481, 468, 431, 715, 145, 355, 488, 
        873, 387, 149, 538, 853, 421, 708, 257, 553, 756, 12, 752, 809, 318, 567, 417, 779, 519, 892, 78, 773, 
        998, 520, 679, 690, 671, 413, 454, 881, 885, 602, 534, 693, 258, 719, 925, 50, 727, 107, 403, 506, 613, 
        167, 465, 190, 198, 252, 866, 289, 685, 991, 345, 909, 913, 490, 161, 236, 37, 780, 108, 34, 450, 639, 
        427, 938, 414, 689, 51, 446, 704, 75, 320, 937, 383, 697, 52, 694, 982, 56, 169, 168, 230, 443, 8, 225, 
        321, 151, 559, 560, 314, 751, 766, 109, 854, 855, 229, 309, 187, 331, 324, 935, 218, 106, 59, 900, 540, 
        763, 263, 483, 949, 393, 758, 620, 666, 260, 217, 683, 32, 737, 241, 165, 828, 477, 735, 884, 522, 38, 
        353, 515, 155, 391, 576, 861, 945, 196, 554, 14, 392, 35, 784, 147, 305, 370, 705, 438, 610, 68, 815, 
        972, 781, 793, 142, 99, 932, 425, 582, 180, 501, 971, 748, 659, 835, 193, 628, 609, 70, 973, 994, 978, 
        440, 898, 53, 273, 764, 422, 663, 867, 637, 254, 662, 640, 166, 643, 601, 205, 989, 220, 73, 174, 904, 
        176, 405, 136, 654, 227, 514, 848, 785, 826, 788, 57, 573, 765, 269, 160, 730, 630, 869, 670, 917, 215, 
        436, 171, 676, 411, 302, 361, 367, 725, 922, 114, 657, 249, 388, 701, 378, 903, 364, 517, 928, 272, 382, 
        988, 389, 299, 10, 832, 775, 63, 163, 98, 375, 936, 223, 65, 532, 544, 232, 767, 20, 137, 442, 908, 696, 
        952, 700, 400, 681, 523, 583, 335, 179, 408, 729, 462, 960, 795, 58, 451, 821, 200, 306, 979, 805, 626, 
        762, 113, 250, 177, 720, 584, 184, 552, 841, 150, 475, 934, 563, 787, 645, 2, 152, 433, 619, 653, 692, 
        478, 19, 557, 623, 505, 67, 182, 304, 531, 814, 656, 444, 615, 586, 29, 496, 270, 734, 62, 887, 843, 173, 
        633, 17, 507, 266, 877, 28, 470, 248, 281, 476, 3, 840, 15, 985, 315, 707, 334, 943, 668, 238, 228, 882, 
        863, 723, 833, 778, 647, 452, 81, 880, 301, 368, 92, 124, 498, 497, 139, 191, 474, 45, 526, 489, 649, 
        426, 652, 769, 894, 316, 216, 271, 791, 838, 36, 214, 298, 777, 733, 616, 816, 420, 996, 545, 714, 482, 
        516, 834, 491, 143, 82, 120, 275, 513, 178, 5, 822, 18, 325, 380, 732, 743, 588, 634, 886, 688, 799, 340, 
        746, 133, 606, 207, 449, 466, 132, 596, 824, 434, 617, 326, 661, 641, 796, 365, 219, 966, 283, 530, 736, 
        338, 682, 871, 327, 600, 555, 624, 329, 282, 529, 9, 899, 711, 123, 883, 231, 192, 366, 284, 870, 803, 
        406, 543, 950, 247, 158, 818, 363, 213, 134, 565, 130, 605, 55, 890, 651, 312, 343, 233, 210, 439, 295, 
        347, 42, 804, 940, 336, 127, 457, 859, 831, 103, 916, 672, 897, 718, 125, 802, 287, 374, 463, 239, 13, 
        234, 684, 790, 197, 64, 680, 920, 350, 801, 716, 162, 445, 410, 837, 995, 844, 288, 798, 646, 415, 148, 
        739, 485, 156, 105, 469, 858, 47, 322, 986, 499, 857, 820, 710, 41, 548, 789, 749, 221, 357, 709, 39, 
        847, 86, 598, 518, 358, 202, 912, 712, 48, 115, 226, 441, 332, 665, 528, 581, 84, 384, 121, 83, 212, 510, 
        713, 575, 509, 186, 570, 211, 860, 244, 957, 341, 61, 23, 111, 195, 983, 181, 902, 330, 310, 351, 359, 
        93, 118, 760, 455, 397, 110, 768, 542, 253, 16, 961, 484, 655, 907, 500, 813, 328, 800, 122, 874, 755, 
        782, 992, 625, 129, 395, 493, 460, 504, 432, 675, 963, 416, 131, 810, 997, 402, 976, 135, 290, 209, 435, 
        346, 90, 927, 235, 895, 905, 808, 551, 944, 296, 546, 825, 535, 313, 830, 429, 297, 303, 794, 585, 587, 
        731, 377, 243, 631, 962, 740, 242, 206, 851, 823, 307, 722, 537, 604, 564, 664, 418, 119, 776, 246, 
        759, 933, 852, 31, 754, 237, 571, 348, 574, 929, 648, 276, 846, 140, 819, 459, 308, 622, 829, 360, 
        836, 291, 827, 771, 164, 458, 521, 349, 864, 447, 539, 256, 638, 104, 40, 931, 724, 876, 757, 208, 
        698, 919, 967, 430, 46, 590, 939, 1, 695, 71, 480, 817, 30, 333, 566, 453, 611, 750, 456, 183, 201, 
        43, 618, 203, 240, 423, 292, 294, 924, 100, 673, 245, 101, 494, 593, 955, 862, 188, 373, 761, 677, 
        69, 44, 199, 550, 60, 990, 194, 54, 153, 745, 394, 495, 597, 589, 386, 901, 549, 607, 317, 185, 22, 
        344, 286, 956, 385, 687, 116, 11, 941, 686, 770, 568, 94, 21, 502, };

    int n = sizeof(array)/sizeof(array[0]); 
    
    MergeSort(array , 0 , n-1);

    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}

