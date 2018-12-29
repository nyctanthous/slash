#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asprintf.h"
#define put(index, char_array) (index >= 0? (char_array[index--]) : "")

char** aldos_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(17 * sizeof(char *));
    asprintf(&out[0],  "%s                            %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s           # ## #           %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s        # ######## #        %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s      # ### ######## #      %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s     # #### ######### #     %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s   # #### # # # # #### #    %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s  # ##### #       ##### #   %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s   # ###### ##### #### #    %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s    # ############### #     %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s                            %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s         _ ___   ___  ___   %s", c2, put(num_info_lines, info));
    asprintf(&out[11], "%s    __ _| |   \\ / _ \\/ __|  %s", c2, put(num_info_lines, info));
    asprintf(&out[12], "%s   / _' | | |) | (_) \\__ \\  %s", c2, put(num_info_lines, info));
    asprintf(&out[13], "%s   \\__,_|_|___/ \\___/|___/  %s", c2, put(num_info_lines, info));
    asprintf(&out[14], "%s                            %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s                            %s", c1, put(num_info_lines, info));
    out[16] = 0;

    return out;
}

/* REVISE */
char** alpine_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s                                        %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s          :yyyyyyyyyyyyyyyyyy:          %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s         /dddddddddddddddddddd/         %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s        oddddddddddddddddddddddo        %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s      `sdddddddddddddddddddddddds`      %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s     `yddddddddd+odddddddddddddddy`     %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s    .hdddddddh+`  .odds..oddddddddh.    %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s   -dddddddh+`  .`  .:`   .odddddddh-   %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s  /ddddddh+`  .odd+`  `-/`  .oddddddd/  %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s  /ddddh+`  ./-hdddd+`  .+/`  .oddddd/  %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s   -hdd/.`.oy-`hdddddd+.`.oh+.`.oddh-   %s", c1, put(num_info_lines, info));
    asprintf(&out[11], "%s    .hddddddddddddddddddddddddddddh.    %s", c1, put(num_info_lines, info));
    asprintf(&out[12], "%s     `yddddddddddddddddddddddddddy`     %s", c1, put(num_info_lines, info));
    asprintf(&out[13], "%s      `sdddddddddddddddddddddddds`      %s", c1, put(num_info_lines, info));
    asprintf(&out[14], "%s        oddddddddddddddddddddddo        %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s         /dddddddddddddddddddd/         %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s          :yyyyyyyyyyyyyyyyyy:          %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s                                        %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** antergos_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(20 * sizeof(char *));
    asprintf(&out[0],  "%s                 .://:-                %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s              .sdmmmmmmdy.             %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s             .hmmmmmmmmmmmmd.          %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s          .ymmmmmmmmmmmmmmmmd.         %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s         /dmmmmmmmmdhdmdmmmmmms`       %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s        smmmmmmmmhs:.hm/dmddmmmh-      %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s      .ymmmmmdhs:.%s-%s`ymy%s-%s+md/sdmmd:     %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s     -hmmmyo/-`%s---%s-hmd-%s-%s.mmy%s-%s:dmmd+    %s", c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s    -dmmms%s------%s`odmmo%s---%sdmm/%s-%s-dmmd+   %s", c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s   -dmmmm.%s----%s.+hmmmy`%s---%shmmh%s--%ssmmmd+  %s", c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s   hmmmmd%s---%s-odmmmmh`%s----%sdmmm-%s-%sommmmd- %s", c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[11], "%s  ommmmmm/+hdmmmmmy.%s----%s`mmmm+%s-%symmmmmh %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[12], "%s  dmmmmmmmmmmmmmms`%s-----%s/mmmmo/mmmmmmm %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s  mmmmmmmmmmmmmd/%s------%s`hmmmmhdmmmmmmm %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s  ommmmmmmmmmms.%s-------%sommmmmmmmmmmmmh %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[15], "%s   +dmmmmmmmmmds+:--.-+mmmmmmmmmmmmms  %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s    `/ydmmmmmmmmmmddddmmmmmmmmmmdy+.`  %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s       `.:+osyhhddddddddhhyso+/-``     %s", c1, put(num_info_lines, info));
    asprintf(&out[18], "%s                `````````              %s", c1, put(num_info_lines, info));
    out[19] = 0;
    return out;
}

char** arch_old_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s                 __                    %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s            _=(SDGJT=_                 %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s          _GTDJHGGFCVS)                %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s         ,GTDJGGDTDFBGX0               %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s        JDJDIJHRORVFSBSVL%s-=+=,_        %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[5],  "%s       IJFDUFHJNXIXCDXDSV,%s  \\\"DEBL     %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[6],  "%s      [LKDSDJTDU=OUSCSBFLD.%s   '?ZWX,   %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[7],  "%s     ,LMDSDSWH'     \\`DCBOSI%s     DRDS],%s", c1, c2, put(num_info_lines, info));
    asprintf(&out[8],  "%s     SDDFDFH'         !YEWD,%s   )HDROD  %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[9],  "%s    !KMDOCG            &GSU|%s\\_GFHRGO\'  %s", c1, c2, put(num_info_lines, info));
    asprintf(&out[10], "%s    HKLSGP'%s           __%s\\TKM0%s\\GHRBV)'  %s", c1, c2, c1, c2, put(num_info_lines, info));
    asprintf(&out[11], "%s   JSNRVW'%s       __+MNAEC%s\\IOI,%s\\BN'     %s", c1, c2, c1, c2, put(num_info_lines, info));
    asprintf(&out[12], "%s   HELK['%s    __,=OFFXCBGHC%s\\FD)         %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s   ?KGHE %s\\_-#DASDFLSV='%s    'EF         %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s   'EHTI                    !H         %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s    \\`0F'                    '!        %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s                                       %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s                                     %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** arch_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s                  .o+                  %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s                  ooo/                 %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s                 +oooo:                %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s                +oooooo:               %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s               -+oooooo+:              %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s              /:-:++oooo+:             %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s             /++++/+++++++:            %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s            /++++++++++++++:           %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s           /+++o%soooooooo%soooo/`         %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9], "%s         %s./%sooosssso++osssssso%s+`        %s", c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s        .oossssso-````/ossssss+`       %s", c2, put(num_info_lines, info));
    asprintf(&out[11], "%s       -osssssso.      :ssssssso.      %s", c2, put(num_info_lines, info));
    asprintf(&out[12], "%s      :osssssss/        osssso+++.     %s", c2, put(num_info_lines, info));
    asprintf(&out[13], "%s     /ossssssss/        +ssssooo/-     %s", c2, put(num_info_lines, info));
    asprintf(&out[14], "%s    /ossssso+/:-        -:/+osssso+-   %s", c2, put(num_info_lines, info));
    asprintf(&out[15], "%s   +sso+:-`                 `.-/+oso:  %s", c2, put(num_info_lines, info));
    asprintf(&out[16], "%s  ++:.                           `-/+/ %s", c2, put(num_info_lines, info));
    asprintf(&out[17], "%s .`                                 `/ %s", c2, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** artix_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s           `-/:-`       `-:/-          %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s       `+hNm:             :NNh/`       %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s     .sNMMy..            `..yMMNs.     %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s   `oNNNMo  y:           :s  sMNNN+    %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s  `hMMo:o.  Nh           hN  .o-sMMy   %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s `dMMMM/+y-`hMo` `   ` `oMy`-y++MMMMh  %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s sMMMMMd.odh+NMd/y` `y/dMN+hdo-mMMMMM+ %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s NMMMMMMm/`oMNMMMMdhmMMMMNMo`/mMMMMMMm %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s MMMMMMMMs  NMMMMMMMMMMMMMN  yMMMMMMMM %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s MMMMMMMMN: /dMMdMMMMNmMMd/ /MMMMMMMMM %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s NMMMMMMMMNo  dNhyMMNsmNd  sNMMMMMMMMm %s", c1, put(num_info_lines, info));
    asprintf(&out[11], "%s +MMMMMMMMMMmo: \\dMMMd/ /smMMMMMMMMMM  %s", c1, put(num_info_lines, info));
    asprintf(&out[12], "%s  yMMMMMMMMMMMN. -MMM- -NMMMMMMMMMMMs  %s", c1, put(num_info_lines, info));
    asprintf(&out[13], "%s  `sMMMymMm.oNMd.'yMy'.dMmo.NMdhMMMo   %s", c1, put(num_info_lines, info));
    asprintf(&out[14], "%s    :dMm/+h: .sMd` - .mNo` /h//NMd:    %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s     `/hNy-.`  -hd  `my.  `.-hNh:      %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s        .+ys:    :: ::    :yy+`        %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s            -:.         .:.            %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** blag_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s    .+::::::::::::::::::::::::::+.    %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s    |/            %s-o%s            \\|    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s    |            %s:NMs%s            |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s    |           %s:NMMMy`%s          |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s    |    %s-:/+osyNMMMMMdyso+/:`%s   |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s    |    %s:hNMMMMMMMMMMMMMMMm+`%s   |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s    |      %s-yNMMMMMMMMMMMd/`%s     |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s    |        %s/MMMMMMMMMMh`%s       |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s    |        %ssMMMMMMMMMMN%s        |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s    |        %smMNds:-+hmMM:%s       |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s    |       %s.s/.`     `-++%s       |    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[11], "%s    |                            |    %s", c1, put(num_info_lines, info));
    asprintf(&out[12], "%s    |............................|    %s", c1, put(num_info_lines, info));
    asprintf(&out[13], "%s    %s88\"\"Yb 88        db     dP\"\"b8%s    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s    %s88__dP 88       dPYb   dP   `\"%s    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[15], "%s    %s88\"\"Yb 88  .o  dP__Yb  Yb  \"88%s    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[16], "%s    %s88oodP 88ood8 dP\"\"\"\"Yb  YboodP%s    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[17], "%s    '++/::::::::::::::::::::::\\++'    %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** blank_on_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s `shhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhho` %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s hMMMMMMMMmho+::::/+shNMMMMMMMN%sdhhd%sNy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s hMMMMMmo.             :sNMMMMh%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s hMMMm/        .-.       `oNMMy%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s hMMy`     +hNMMMMMmy/     .dMy%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s hMy     +NMMMMMMMMMMMm:    `my%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s hN`    oMMMMMMMMMMMMMMM:    :y%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s hy     NMMMMMMMMMMMMMMMd     y%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s hs     NMMMMMMMMMMMMMMMd     y%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s hm     sMMMMMMMMMMMMMMM/    .y%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[11], "%s hM+     oNMMMMMMMMMMMN/     hy%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[12], "%s hMN/     .odMMMMMMNd+`     yMy%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s hMMMy`      `-:::'       -dMMh%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s hMMMMNs-               :hMMMMh%syyyy%sdy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[15], "%s hMMMMMMMmy+-.     .:+hNMMMMMMm%sdhhd%sNy %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[16], "%s yMMMMMMMMMMMMMNNMMMMMMMMMMMMMMMMMMMs %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s `oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+` %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** debian_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s               ./osso+++/-.            %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s           :ohhhhhsssssyhhhy+:         %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s         /yhhyo/.        -+hhhy:       %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s       .shho:`             `+hhhs`     %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s      -yh+`         ...      -hh/-     %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s     .hh/         //:---`     oho`     %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s     oh+        .+`           :hy      %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s     oh-        y`            :ho      %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s     oh`        y-           `oy`      %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s     oh.        -s.         .s+`       %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s     :h+        ..++:.  .-+o+.         %s", c1, put(num_info_lines, info));
    asprintf(&out[11], "%s     `yh:`        `-:/++:-.            %s", c1, put(num_info_lines, info));
    asprintf(&out[12], "%s      .hho                             %s", c1, put(num_info_lines, info));
    asprintf(&out[13], "%s       .yh:                            %s", c1, put(num_info_lines, info));
    asprintf(&out[14], "%s        `oh+`                          %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s          .oy/`                        %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s            `/s+`                      %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s               `-:-.`                  %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** fedora_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s               ..........              %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s          ....................         %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s        .............%s/syhdhyo-%s..       %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s      ............%s-yNMMMMMMMMo/:-%s.     %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s    .............%s/NMMMNyoooso////-%s..   %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s   .............%s-NMMMy-%s......%s:////-%s..  %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s  ..............%s+MMMN%s.........%s:///-%s... %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s `..............%s+MMMm%s........%s-////-%s...`%s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s ...............%s+MMMN%s......%s-:////:%s.....%s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s ......%s-::/hNNNNNMMMMNNNNms/////:%s......%s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s ....%s:////+NMMMMMMMMMMMMMMy//:-%s........%s", c1, c2, c1,  put(num_info_lines, info));
    asprintf(&out[11], "%s ..-%s/////:%s--::::%ssMMMN%s::::--...........`%s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[12], "%s ..%s:///:%s........%s+MMMN%s................. %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s ..%s////%s-........%s+MMMm%s................  %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s ..%s:///:%s.......%s-dMMMh%s...............   %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[15], "%s ..%s-///////%s::%s/sNMMMm-%s.............`    %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[16], "%s ....%s://dMMMMMMMMNs-%s............`      %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[17], "%s ......%s-+dNNNNdy+-%s............`        %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[18], "%s  `......................'`            %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** mint_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));
    asprintf(&out[0],  "%s                                       %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s KNNNNNNNNNNNNNNNNNNNNNNNNNXXKK        %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s XMMMMMMMWWWWMMMMMMMMMMMMMMMMMWWXK     %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s XWMMMMMMN%s--%sXMMMMMMMMMMMMMMMMMMMMWX    %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s  KKKNWMWX%s--%sXMMMMWNXXXXXNNNXKXXNWMWN   %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s      NMWX%s--%sXWMWN%s---------------%sKNMWX  %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s      NMWX%s--%sXWMN%s----%sXNNK%s---%sXNNK%s--%sKWWX  %s", c1, c2, c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s      NMWX%s--%sXWMN%s---%sXNMMX%s--%sKWMWX%s--%sKWWX  %s", c1, c2, c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s      NMWX%s--%sXWMN%s---%sXNMMN%s---%sWMMX%s--%sKWMX  %s", c1, c2, c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s      NMWX%s--%sXWMN%s---%sXNMMN%s--%sKWMMX%s--%sKWMX  %s", c1, c2, c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[10], "%s      NMWX%s--%sXWMWXXNNWMMWXXNWMWX%s--%sKWWX  %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[11], "%s      NMMX%s--%sKWMMMMMMMMMMMMMMMWK%s--%sKWWX  %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[12], "%s      XWMWK%s---%sXXXXXXXNXNXXNXX%s----%sNMMX  %s", c1, c2, c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[13], "%s       XWWWXK%s-----------------%sKXWWMMX  %s", c1, c2, c1, put(num_info_lines, info));
    asprintf(&out[14], "%s        KNWMWWNNNNNNNNNNNNNNNWWMMMMWX  %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s          KXNWWWWMMMMMMMMMMMMMWMMWWNK  %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s               KKKKKKKKKKKKKKKKKKK     %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s                                       %s", c1, put(num_info_lines, info));
    out[18] = 0;

    return out;
}

char** ubuntu_logo(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));      
    asprintf(&out[0],  "%s                                       %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s                           :oo+:       %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s                  `..--..`-sssss-      %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s              ` .ssssssss+`/sss/       %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s            .+so`-sso++osss/:-:.       %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s           /ssss/        `-+ssss/      %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s          /ssso.            .osss/     %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s     .-:.`osss`              `ssss-    %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s    :sssso os/                -///-    %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s    /sssso os/                -///-    %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s     .::.`osss`              `ssss-    %s", c1, put(num_info_lines, info));
    asprintf(&out[11], "%s          /ssso.            .osss+     %s", c1, put(num_info_lines, info));
    asprintf(&out[12], "%s           /ssss/        `-+ssss/      %s", c1, put(num_info_lines, info));
    asprintf(&out[13], "%s            .+so`-sso++ooss/:-:.       %s", c1, put(num_info_lines, info));
    asprintf(&out[14], "%s              ` .sssssssso`/sso/       %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s                  `.----.`-sssss-      %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s                           :ooo:       %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s                                       %s", c1, put(num_info_lines, info)); 
    out[18] = 0;
    return out;
}

char** tux(char *c1, char *c2, char **info, int num_info_lines){
    char **out = malloc(19 * sizeof(char *));      
    asprintf(&out[0],  "%s                 `-::::-.                 %s", c1, put(num_info_lines, info));
    asprintf(&out[1],  "%s             `/ss+::://+oss+`             %s", c1, put(num_info_lines, info));
    asprintf(&out[2],  "%s           `sdsshmNMMMMMMNmmMy.           %s", c1, put(num_info_lines, info));
    asprintf(&out[3],  "%s          :NNNMMdhdNMMMMMMMMMMM+          %s", c1, put(num_info_lines, info));
    asprintf(&out[4],  "%s         :MMMMm/..-/mMNdsoymMMMM+         %s", c1, put(num_info_lines, info));
    asprintf(&out[5],  "%s         dMMMh     `.h:   `:NMMMN`        %s", c1, put(num_info_lines, info));
    asprintf(&out[6],  "%s         MMMM/     hd+m/    +MMMM-        %s", c1, put(num_info_lines, info));
    asprintf(&out[7],  "%s        :MMMMm.   .//+o/`  .dMMMMh        %s", c1, put(num_info_lines, info));
    asprintf(&out[8],  "%s       :hNMMMMMy../+:-/o--yMMMMMmso:`     %s", c1, put(num_info_lines, info));
    asprintf(&out[9],  "%s    .++/sNMMMd/     :+-    -hMMMMmo:+o-   %s", c1, put(num_info_lines, info));
    asprintf(&out[10], "%s  .so:+mMMMMs                +MMMMMmo-+o` %s", c1, put(num_info_lines, info));
    asprintf(&out[11], "%s /o:odMNmMMd                  sMMMsNMms/o.%s", c1, put(num_info_lines, info));
    asprintf(&out[12], "%s:symMNs`-MMo                  :MMy `+hNNdo%s", c1, put(num_info_lines, info));
    asprintf(&out[13], "%s-syo-    /My                  oMd`     .. %s", c1, put(num_info_lines, info));
    asprintf(&out[14], "%s          :m+/+oo/`     ./++//Ns          %s", c1, put(num_info_lines, info));
    asprintf(&out[15], "%s          /+-```-+ds  -dy/.`../+`         %s", c1, put(num_info_lines, info));
    asprintf(&out[16], "%s         +:```````:my.Ns.``````.o         %s", c1, put(num_info_lines, info));
    asprintf(&out[17], "%s         :---------//-+:--------:`        %s", c1, put(num_info_lines, info));
    out[18] = 0;
    return out;
}