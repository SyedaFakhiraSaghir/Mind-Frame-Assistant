#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// functions to generate random numbers
// for asking user to enter what they feel
int display_w();

// for outputing a question
int display_x();

// for outputing an answer
int display_y();

//to read strings of questions from file
void get_questions();

void get_AskQ();

//to read answers from files
void get_Reply();

void get_Answers();

struct Questions
{
	
    char questions[10][200];
    
} question;

struct Ask_Q
{
	
    char ask_questions[5][200];
    
} aques;

struct Reply
{
    char happy_re[10][200];
    char sad_re[10][200];
    char scared_re[10][200];
    char angry_re[10][800];
    char surprised_re[10][200];
    char disgusted_re[10][200];
} rep;

struct Answers
{
    char answers[22][200];
} ans;

int main()
{
    printf("\033[0;36m");
    printf("\t\t\t\t\tMIND FRAME ASSISTANT\n");
    printf("\033[0;37m");
    printf("\t\t\t\t     **************************\n");

    get_questions();
    get_Reply();
    get_AskQ();
    get_Answers();

    int i, n;
    int c = 0;
    int emp = 0;

    // in is the termination of the question loop
    int input = 0, in = 0;

    // random numbers

    int w, x, y;

    // declaring user input which will be used to determine the mood

    char user_input[200], ques[200];

    // pointer for function strtok()
    char *ptr;

    // switch case
    int choice;

    // strings for synynoms
    char sad[330][200]={"sad","tired","tensed","cry","acheronian","acherontic","aching","achy","afflicted","affliction","afflictive","aggrieved"
	    , "agitated","agonizing","agony","all torn up",
         "altered","amazed","anguish","annoyed","annoying","antsy","anxious","apprehensive","arduous","awful","bad","basket case","bemoaning","bereaved","bereavement",
		 "bewailing","biting","bitter" ,"black","bleak","blue","bothered","broken up","bugged","bummed out","bundle of nerves","burning","capsized",
         "care","caustic","changed","chaotic","chapfallen","cheerless","cold","come apart","comfortless","compassionate","concerned",
		 "confused","crestfallen","critical","crushed","crushing","cursed","cut up","damaged","daunting","dejected",
         "demoralizing","deploring","depressant","depressed","depressing","depression","depressive","desolate","desolation","despair",
         "despairing","despondency","despondent","destroyed","difficult","dire","disagreeable","disappointed","discombobulated","discomfort",
         "disconcerted","disconsolate","discouraged","discouraging","disheartening","dismal","dismayed","disordered","dispirited","dispiriting","disquiet",
         "disquieted","distasteful","distracted","distrait","distraught","distress","distressed","distressing","disturbed","dole","doleful","dolor","dolorous",
         "down","down and out","down in dumps","down in the mouth","downbeat","downcast","downhearted","drab","dragged","dreadful","dreary","droopy","dull",
         "dusky","excited", "excruciating","exercised","extreme","extremely bad","fidgety","forlorn","frantic","funereal",
		 "gloom","gloomy","glum","grief-stricken","grievance","grieved","grieving","grievous","grim","harassed","harassment","hard","harmed","harrowing",
		 "have the blahs","heartache","heartbreak","heartbreaking","heartbroken","heartsick",
         "heartsore","heavy","heavy-hearted","hopeless","hurt","hurtful","hurting","hyper","ill","impaired","impressed","in-a-blue-funk","in-a-stew","in-a-tizzy","blue-funk",
		 "disarray""doldrums","grief","pain","in the dumps","inconsolable","indignant","infelicity","inflamed","influenced","injured","irked","irritated","jittery",
		 "joyless","jumpy","laborious","lachrymose","lamentation","lamenting","languishing","let-down",
         "long-faced","low","low-spirited","lugubrious","malaise","melancholic","melancholy","miffed","mirthless","miserable","misery","moody","moony","mopey","morbid","morose","mortification",
         "mournful","mournfulness","mourning","muddled","nagging","not happy","oppressed","oppressive","out of sorts","overturned""overwhelmed","overwrought""pain","pained","peeved","pensive",
		 "persecuted""perturbed","pessimistic", "piercing","pitiful","pressing","prostrated","psyched-out","purgatory","put out","rattled","raw","regret","remorse",
		 "repining","resentful","ripped","rue","rueful","ruffled","sad", "saddened","saddening","sadness","sensitive","severe","shaky","sharp","shocked","shook",
		 "shook-up","shot down","sick","sick at heart","smarting","somber","sore","sorrow","sorrowful",
          "sorry","spilled","spooked","stimulated","stinging","stirred","stricken","strung-out","stung","suffering","sympathetic","teary","tedious","tender","tenebrific",
         "terrible","throbbing","thrown","tipped over","toppled","tormented","tormenting","torn-up","torture","touched","trial","tribulation","trite","trouble","troubled","troublesome",
          "trying","tumbled","uncomfortable","unconsolable","unglued","unhappiness","unhappy","unpleasant","unsettled","unzipped","up the wall","upset","upside-down","uptight",
         "urgent","vexation","vexatious","vexed","weeping","weighty","wet blanket","wired","wistful","woe","woebegone","woeful","worried","worry","wretched","wretchedness","wronged","cry","cried","crying","worry","worrying","anxiety"};
    char scared[112][200]={"scared","abhorrence","afraid","aghast","agitation","alarm","alarming","angst","anticipate","anxiety"
	     ,"anxious","apprehend","apprehension","apprehensiveness",
         "aversion","avoid","awe","be afraid","be anxious","be apprehensive","be disquieted","be frightened","be in awe","bête noire","blanch","bloodcurdling",
		 "break out in a sweat","chicken heartedness","chilling",
         "cold feet","cold sweat","concern","consternation","cowardice","cower","creeps","creepy","crouch","dare not","despair","discomposure","dismay","disquietude","distress","doubt","dread","eerie",
		 "expect","faintheartedness","falter","fearful","fearfulness","feel concern","flinch","foreboding","foresee","formidable","fret","fright","funk","hair-raising","hairy","have butterflies",
         "have qualms","having cold feet","horrendous","horrifying","horror","intimidating","jitters","lose courage","misgiving","nightmare","panic","panic-stricken","panicked""panicky","petrified",
         "phobia","presentiment","quail","qualm","quaver","recreancy","redoubtable","reverence","revulsion","scare","shaken","shocking","shrink","shudder","shun","shy","spine-chilling","spooky","start","startled",
         "suspect","suspicion","terrified","terror","terror-stricken","timidity","tremble","trembling","trepidation","unease","uneasiness","unnerving","wilt","worry"};
    char happy[260][30]={"good","happy","accidental","advantageous", "affability","agreeability","agreeableness","alertness","amenity"
	     ,"amiability","amusement","animated","animation",
         "appropriate","apt","auspicious","avidity","beaming","beautiful","befitting","blessed","blest","bliss","blissful","blithe","blitheness","blithesome",
         "blithesomeness","bright","brightness","brilliance","briskness","buoyancy","buzz","can not complain","captivated","casual","charge","cheer","cheerful","cheerfulness",
         "cheeriness","cheering","cheery","chipper""chirpy","cloud nine","color","colorfulness","comfort","congenialness","content","contented","convenient","convivial",
         "conviviality","convulsions","cordiality","correct","crowing","delectation","delight","delighted","dispatch","dreamland","eagerness","ecstasy","ecstatic","effective",
         "effervescence","efficacious","elated","elation","elevation","encouragement","enjoyableness","enjoyment","entertainment","enthusiasm","enviable",
         "euphoria","exaltation","excitement","exhilarated","exhilaration","expedition","exuberance","exultance","exultancy","exultant","exultation",
         "favorable","felicitous","felicity","fervor""festivity","fitting","floating on air","flying high",
         "fortunate","frenzy","friendliness""frivolity","frolic","fun","gaiety","gay","genial","geniality","glad","gladness","glee","gleeful","gleefulness",
         "glitter","gloating","glory","good cheer","good humor","good nature","gratefulness","gratified","gratifying","grins","happiness","health","heartiness"
         ,"high","high spirits","hilarious","hilarity","hopefulness","hysteria","hysterics","incidental","inspiration","intoxicated","intoxication","jauntiness",
         "jocoseness","jocosity","jocularity","jocund","jocundity","joie de vivre","jollies","jolliness""jollity","jolly","jovial","joviality","joy","joyful",
         "joyfulness","joyous","joyousness","jubilance","jubilant","jubilation","just","kick","kicks","kindliness","kindness","laughing","laughs","laughter",
         "levity","light","light-heartedness","lighthearted","lightheartedness","liveliness","lively","looking good","lucky","madness","meet","merriment",
         "merriness","merry","merry-making","merrymaking","mirth","mirthful","mirthfulness","nice","on cloud nine","opportune","optimism","overjoyed""peaceful",
         "peppy","perky","playful","pleasance","pleasant","pleasantness","pleased","pleased as punch","pleasing","pleasure","promising","promptitude""proper",
         "propitious","providential","quickness","radiance","radiant", "rapture","readiness","rejoicing","relaxation","revel","reveling","revelry","right",
         "satisfaction","satisfactory","satisfied","seasonable","shindig","showiness","solace","vsparkle","sparkling","speed","sport","sprightliness",
		 "stars in one nos eyes","stimulation","successful","suitable","sunniness","sunny", "sweetness and light","thrilled","tickled","tickled pink",
		 "tickled to death","timely","transport","triumph","up","upbeat","uplift","upper","verve","vivacity","walking on air","warmheartedness","warmth",
		 "well-timed","whoopee","willing","willingness","wingdin","wingding","zeal","happy"};
    char angry[168][100]={"angry","acrimony","affronted""aggravate","anger""anger","angered","animosity""annoyance","annoyance"
	     ,"annoyed","antagonism","antagonized""bent","bent out of shape",
         "beside oneself","bitter", "blow up","boiling","browned off","bummed out","cat fit","chafed","chagrin","choler""choleric","conniption","convulsed","corybantic","crazed",
         "cross","dander","demented","desperate","disapprobation""discomfort""displeased","displeasure","distemper","enmity","enrage","enraged","exacerbated","exasperate","exasperated","exasperation",
         "exasperation","excitability","ferocious","fierce","fiery","fit to be tied","frantic","frenetic","frenzied","fume","fuming","furious","fury","gall","galled","hacked",
         "hateful","hatred","heated","hissy fit","hopping mad","hot","huff","huffy","hypersensitivity","ill humor","ill temper","ill-tempered","impassioned","impatience","in fringing","in-fringing",
         "incense","incensed","indignant","indignation","inflamed","inflammation","infringing","infuriated","infuriating","infuriation","insane","irascibility","irascible","irate","ire","ireful",
		 "irrational","irritability", "irritable","irritate","irritated","irritation","livid","mad","madden","maddened","make blood boil","maniac","miff","nettled","offended","outrage","outraged",
		 "oversensitiveness","oversensitivity","passion","peevishness","petulance","pique","piqued","pissed","pissed off","provocation","provoke","provoked","put out","rabid","rage",
		 "raging","rankling","rawness", "resentful","resentment","rile","riled","slow burn","smoking","sore","soreness","soreness","splenetic","steamed","stew","storm","storming","stress","sulky","sullen",
         "susceptibility","susceptibleness","T-off","tantrum","temper","tenderness","tenseness","tiff","umbrage","unreasonable","up in arms","upset","uptight","vehement","vexation"
		 ,"vexation","vexed","vicious","violence","violent","wrathful"};
    char surprised[141][15]={"surprised","abruptness","accidental","alarmed","amaze","amazed","amazing","astonished","astonishing"
	     ,"astound","astounded",
		 "astoundment","attack","awe","bewilder","bewildered","bewilderment","blowAway","bombshell","bushwhack","capture","chance","confound",
		 "confounded","confuse","consternate","consternation","curiosity","curveball","daze","dazed","dazzle","disappointment","discomfit",
		 "disconcert","discover","disillusion","dismay","dumbfound","electrify","electrifying","epiphany","eureka","extraordinary","flabbergast","floor",
		 "fortuitous","fortune","frightened","godsend","grab","grasp","impulsive","incredulity","jar","jolt","kick","marvel","miracle","miscalculation","nab",
		 "nonplus","overwhelm","perplex","petrify","phenomenon","portent","precipitance","prodigy","rarity","rattle","remarkable","revelation","rock","seize","shock",
		 "shocked","shocking","stagger","start","stun","stunned","stunning","stupefaction","stupefied","sudden","surprised","take","thunderbolt",
		 "unanticipated","unexpected","unforeseen","unpredictable","unsettle","waylay","whammy","wonder","wonderful","flabbergasted","mind blowing","mind boggling"};
    char disgusted[127][15]={"disgusted","abhorred","abhorrence","antipathy","appalled","aversion","beastly","bother"
	     ,"cloy","cloying","creepy",
         "detestable","detestation","disenchant","dislike","displease","displeased","distaste","distasteful","disturb",
		 "fastidious","foul","frightful","ghastly","grody","gross","gruesome","hateful","hatefulness","hatred","hideous","horrid","horrific","icky","insult","irk","loathing",
		 "loathsome","lousy","macabre","monstrous","nasty","nausea","nerdy","noisome","objection","objectionable","obnoxious","odious","offend","offensive","outrage","outraged",
		 "outrageous","overwrought","pall","pique","queasy","reluct","repelled","repellent","repugnance","repugnant","repulse","repulsed","repulsion","revolt","rotten","satiated",
         "satiating","satiation","satiety","scandalize","scuzzy","shameless","shock","shocking","sick","sick_of","sicken","sickness","sleazeball","sleazy","squeamish","stinking"
         "surfeit","surfeiting","tired","turn_off","turned_off","unhappy","upset","vile","vulgar","weary","yecchy","yucky"};
    char motivational_re[10][200]={ "Be strong now because things will get better. It might be stormy now, but it can’t rain forever",
							   "There is only one thing that makes a dream impossible to achieve: the fear of failure",
							   "Happiness is contagious, spread this among people surrounding you",
							   "There is no path to happiness; happiness is the path",
							   "Good is not enough. You’ve got to be great",
							   "If opportunity doesn’t knock, build a door",
							   "It is never too late to be what you might have been",
							   "Always do your best. What you plant now, you will harvest later",
							   "Believe you can and you are halfway there",
							   "Change your thoughts and you change your world"	};
	char motivational_books[10][200]={"The power of positive thinking","The power of now","The magic of thinking big",
	                             "The Art of Happiness","The 5 second rule","Long walk to freedom","Drive",
	                             "Think and grow rich","Dont sweat the small stuff","Awaken the giant within"};
	
    while (1)
    {
        /*Determining the mood*/
        w = 0;
        // generating random numbers to display the messages
        w = display_w();
        // displaying message for user to input what they feel
        printf("%s\n", question.questions[w]);
        // user input about how they feel
        fflush(stdin);
        scanf("%[^\n]s\n", user_input);
        /* counting number of words in the user input
        for (i = 0; user_input[i] != '\0'; i++)
        {
            if (user_input[i] == ' ' && user_input[i] != ' ')
                c++;
        }*/
        emp = 0;
        ptr = strtok(user_input, " ");
        while (ptr != NULL)
        {
            // checking the string if synonyms of happy are present
            for (i = 0; i < 260; i++)
            {
                if (strcmp(ptr, happy[i]) == 0)
                {
                    w = display_w();
                    printf("Mood determined: You feel Happy\n");
                    printf("%s\n", rep.happy_re[w]);
                    emp++;
                    break;
                }
            }
            
            // making sure if one match is found only that mood gets determined
            if (emp > 0)
            {
                break;
            }


            // checking the string if synonyms of sad are present
            for (i = 0; i < 330; i++)
            {
                if (strcmp(ptr, sad[i]) == 0)
                {
                    w = display_w();
                    printf("Mood determined: You feel Sad\n");
                    printf("%s\n", rep.sad_re[w]);
                    emp++;
                    break;
                }
            }

            // making sure if one match is found only that mood gets determined
            if (emp > 0)
            {
                break;
            }
            
            // checking the string if synonyms of scared are present
            for (i = 0; i < 260; i++)
            {
                if (strcmp(ptr, scared[i]) == 0)
                {
                    w = display_w();
                    printf("Mood determined: You feel Scared\n");
                    printf("%s\n", rep.scared_re[w]);
                    emp++;
                    break;
                }
            }

            // making sure if one match is found only that mood gets determined
            if (emp > 0)
            {
                break;
            }

            // checking the string if synonyms of angry are present
            for (i = 0; i < 168; i++)
            {
                if (strcmp(ptr, angry[i]) == 0)
                {
                    w = display_w();
                    printf("Mood determined: You feel Angry\n");
                    printf("%s\n", rep.angry_re[w]);
                    emp++;
                    break;
                }
            }

            // making sure if one match is found only that mood gets determined
            if (emp > 0)
            {
                break;
            }

            // checking the string if synonyms of surprised are present
            for (i = 0; i < 141; i++)
            {
                if (strcmp(ptr, surprised[i]) == 0)
                {
                    w = display_w();
                    printf("Mood determined: You feel Surprised\n");
                    printf("%s\n", rep.surprised_re[w]);
                    emp++;
                    break;
                }
            }

            // making sure if one match is found only that mood gets determined
            if (emp > 0)
            {
                break;
            }

            // checking the string if synonyms of disgusted are present
            for (i = 0; i < 127; i++)
            {
                if (strcmp(ptr, disgusted[i]) == 0)
                {
                    w = display_w();
                    printf("Mood determined: You feel Disgusted\n");
                    printf("%s\n", rep.disgusted_re[w]);
                    emp++;
                    break;
                }
            }
            ptr = strtok(NULL, " ");
        }
        /*n++;*/

        // if no match found then print a default message

        if (emp == 0)
        {
            printf("You feel confused, try again\n");
        }

        printf("\n");
        
		// switch case statements
        printf("\033[0;37m");
        printf("Choose the below mentioned numbers for further assistance : \n");

        // 0 for termination
        printf("\033[0;34m");
        printf("0 : ");
        printf("\033[0;36m");
        printf("Teminate\n");

        // 1 for determining the mood again
        printf("\033[0;34m");
        printf("1 : ");
        printf("\033[0;36m");
        printf("Determine mood again\n");

        printf("\033[0;34m");
        printf("2 : ");
        printf("\033[0;36m");
        printf("Get answer to a yes/No question\n");

        printf("\033[0;34m");
        printf("3 : ");
        printf("\033[0;36m");
        printf("Get a motivational quote\n");

        printf("\033[0;34m");
        printf("4 : ");
        printf("\033[0;36m");
        printf("Get a book suggestion\n");

        printf("\n");
        printf("\033[0;37m");
        printf("Choice : ");
        scanf("%d", &choice);

        /*input=0;
        fflush(stdin);
        printf("Input 1 to exit, 2 to continue determining the mood : ");
        scanf("%d", &input);
        printf("\n");*/

	   switch (choice)
       {
        case 0:
        {
            break;
        }
        case 1:
        {
        	printf("\n");
            continue;
        }
        case 2:
        {
            /*Giving answer to a yes or no question*/
            printf("\033[0;34m");
            printf("\n");
            printf("\t\t\t\tGIVING ANSWER TO A YES/NO QUESTION\n");
            printf("\n");
            printf("\033[0;37m");
            in = 0;
            while (in == 0)
            {
                x = display_x();
                printf("%s\n", aques.ask_questions[x]);
                fflush(stdin);
                scanf("%[^\n]s", ques);
                y = display_y();
                printf("%s\n", ans.answers[y]);
                printf("\nInput 0 to keep asking questions: ");
                scanf("%d", &in);
                printf("\n");
            }
            break;
        }
        case 3:
        {
        	w = display_w();
            printf("%s\n", motivational_re[w]);
            printf("\n");
            break;
        }
        case 4:
        {
        	w = display_w();
            printf("%s\n", motivational_books[w]);
            printf("\n");
            break;
        }
       }
        if( choice==2 || choice==3 || choice==4)
        break;
    }
    return 0;
}

void get_questions()
{
    FILE *fptr;
    fptr = fopen("questions.txt", "r");
    char line[200];
    if (!fptr)
    {
        printf("\n Unable to open questions");
        exit(1);
    }
    int i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(question.questions[i], line);
        i++;
    }
    fclose(fptr);
}

void get_AskQ()
{
    FILE *fptr;
    fptr = fopen("ask_questions.txt", "r");
    char line[200];
    if (!fptr)
    {
        printf("\n Unable to open ask_questions");
        exit(1);
    }
    int i = 0;
    while (fgets(line, 200, fptr) && i < 5)
    {
        strcpy(aques.ask_questions[i], line);
        i++;
    }
}

void get_Reply()
{
    FILE *fptr;
    fptr = fopen("angry_re.txt", "r");
    char line[200];
    if (!fptr)
    {
        printf("\n Unable to open angry_re");
        exit(1);
    }
    int i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(rep.angry_re[i], line);
        i++;
    }
    fclose(fptr);

    fptr = fopen("disgusted_re.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        line[i] = '\0';
    }
    if (!fptr)
    {
        printf("\n Unable to open disgusted_re");
        exit(1);
    }
    i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(rep.disgusted_re[i], line);
        i++;
    }
    fclose(fptr);

    fptr = fopen("happy_re.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        line[i] = '\0';
    }
    if (!fptr)
    {
        printf("\n Unable to open happy_re");
        exit(1);
    }
    i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(rep.happy_re[i], line);
        i++;
    }
    fclose(fptr);

    fptr = fopen("sad_re.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        line[i] = '\0';
    }
    if (!fptr)
    {
        printf("\n Unable to open sad_re");
        exit(1);
    }
    i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(rep.sad_re[i], line);
        i++;
    }
    fclose(fptr);

    fptr = fopen("surprised_re.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        line[i] = '\0';
    }
    if (!fptr)
    {
        printf("\n Unable to open suprised_re");
        exit(1);
    }
    i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(rep.surprised_re[i], line);
        i++;
    }
    fclose(fptr);

    fptr = fopen("scared_re.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        line[i] = '\0';
    }
    if (!fptr)
    {
        printf("\n Unable to open scared_re");
        exit(1);
    }
    i = 0;
    while (fgets(line, 200, fptr) && i < 10)
    {
        strcpy(rep.scared_re[i], line);
        i++;
    }
    fclose(fptr);
}

void get_Answers()
{
	
    FILE *fptr;
    fptr = fopen("answers.txt", "r");
    char line[200];
    if (!fptr)
    {
        printf("\n Unable to open answers");
        exit(1);
    }
    int i = 0;
    while (fgets(line, 200, fptr) && i < 22)
    {
        strcpy(ans.answers[i], line);
        i++;
    }
    fclose(fptr);
    
}

int display_w()
{
    int w;
    srand(time(0));
    w = rand() % 9;
    return w;
};

int display_x()
{
    int x;
    srand(time(0));
    x = rand() % 4;
    return x;
};

int display_y()
{
    int y;
    srand(time(0));
    y = rand() % 21;
    return y;
};