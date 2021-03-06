// long1.c
// created 6-6-97 pickle
#include <ansi.h>

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("饕餮",({"tao tie","tao","tie","long","taotie","dragon"}));
  set("long","龙生九子不成龙，各有所好：饕餮乃第六子，平生好食。\n");
  set("gender", "男性");
  set("age", 28);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1000);
  set("max_sen", 700);
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 60);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",30);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  set_skill("unarmed", 140);
  set_skill("dodge", 150);
  set_skill("force", 150);
  set_skill("parry", 140);
  set_skill("staff", 150);
  set_skill("spells", 120);
  set_skill("seashentong", 100);
  set_skill("dragonfight", 130);
  set_skill("dragonforce", 120);
  set_skill("lunhui-zhang", 150);
  set_skill("dragonstep", 150);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("staff","lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("dodge", "dragonstep");

        set("nkgain", 400);

  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
    (: cast_spell, "hufa" :),
    "饕餮喃喃道：饿了，饿了，该找点东西吃了。\n",
  }) );

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/sea/obj/dragonstaff")->wield();
  carry_object("/d/sea/obj/longzhu6");
}

int accept_fight(object me)
{
  command("consider "+me->query("id"));
  command("jealous");
  command("grin");
  command("say 正好我饿了，吃的就送上门来了！");
  command("kill "+me->query("id"));
  return 1;
}



void die()
{
     object me,who,longzhu,longjin;
     string whoid;
	  me=this_object();
	  if(me->query_temp("longzhu_kill"))
	{
	  sscanf(me->query_temp("longzhu_kill"),"%s",whoid);
	  if (!present(whoid,environment()))
	  return ::die();
	  who=present(whoid,environment());
     if((who->query("fangcun/panlong_longgong")=="begin")&&(who->query_temp("fangcun/panlong_longgong_longzhu")!="done")&&(environment()))
	  {
	       message_vision("\n\n饕餮拱手道："  + RANK_D->query_respect(who) + "武功高强，这颗绿龙珠就送给你了．\n\n",who);
           message_vision("饕餮给$N一颗绿色的龙珠．\n", who);
	 	   message_vision(HIC"饕餮喃喃地念了几句咒语。\n"NOR, who);
    	   message_vision(HIC"\n只见$N脚下突然涌起一股水波，水流过后，$N随之不见了！\n"NOR,me,who);
           longzhu=new("/d/sea/obj/longzhu6");
		   longzhu->move(who);
		   destruct(me);
		   return;    
	  }
	}
	 if(me->query_temp("longjin_kill"))
	{
		  whoid=me->query_temp("longjin_kill");
    	  if (!present(whoid,environment()))
        	  return ::die();
	  	  who=present(whoid,environment());
          if((who->query("fangcun/panlong_hell_18")=="done")&&(who->query("fangcun/panlong_hell_longjin")=="begin")&&(environment()))
		{
			  longjin=new("/d/sea/obj/longjin");
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
      ::die();

}




