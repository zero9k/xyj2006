//�ݹǵ���, kugu-blade.c
//modified 4-17-97 pickle

/*
�ݹǵ� 
�޵׶�֮ɱ�־�ѧ������רע������ʹ�ô����书���
�ݹǵ����ܷ��ӳ��������������в�����������ͨ�ĵ�
�˺�������
*/
// ʬ���Ұ����ʬ���⣬ʬɽѪ������ʬ���꣬�����ʬ����ʬ��
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":                 "ʬ���Ұ",
                "action":
"$N��$n���ܹ�����ȥ������$w���в���$n�����̣�\n"
"����"+HIW"��ʬ���Ұ��"NOR"��Ȼ��Ч���Ƶ�$n��æ����",
                "dodge":                -30,
		"parry":		-35,
                "damage":               50,
                "damage_type":  	"����",
		"dodge_msg":
"$n�����߰˸������俴���Ǳ�������ȴ����ض����$N�Ĺ��ơ�\n",
		"dodge_power":		10,
		"parry_msg":
"$n�ۼ�����������æ�������£�˳����$W��$N���ϵ�����\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "��ʬ����",
                "action":
"��ս�У�$N��Ȼ��$w�������ԣ�ֱͦͦ�ĵ��¡�����$n��֪����֮ʱ��\n"
"$N��$w�綾��һ��ͻȻ��$n��$l��ȥ������һ��"+HIW"����ʬ���꡹"NOR"",
                "dodge":                -35,
		"parry":		-30,
                "damage":               40,
                "damage_type":  	"����",
		"dodge_msg":
"$N�ƺ��Ѿ�������$nʱ��$nͻȻԭ�ؼ�ת����ΪһƬ��Ӱ�����ˡ�\n",
		"dodge_power":		10,
		"parry_msg":
"$n��æʹһ��"+HIW"����ʬ���꡹"NOR"����$Wһ�������Ƽ��˿�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "ʬɽѪ��",
                "action":
"$N����������ɽ����������������$w�����Ŀ�ĺ��⣬����ס$n��ȫ��",
                "dodge":                -40,
		"parry":		-20,
                "damage":               65,
                "damage_type":  	"����",
		"dodge_msg":
"$nƽƽԾ���ڿ�����ת��Ȧ������$N����ԭ����"+HIR"��ʬɽѪ����"NOR"��\n",
		"dodge_power":		10,
		"parry_msg":
"$nչ��$W���ӣ��������쵶Ӱ������"+HIR"��ʬɽѪ����"NOR"��Ȼ��$N�Ĺ��Ƶ��˻�ȥ��\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "��ʬ��",
                "action":
"$N��Ȼ����ɫ�԰ף�������������ʧ�ںڰ��С�$n�ڼ�ս��ͻȻ�����˵��ˣ�\n"
"����ʧ��䣬$N������"+HIW"����ʬ�𼣡�"NOR"�İ��н�����һ����$n�ĺ��Կ�ȥ",
                "dodge":                -30,
		"parry":		-20,
                "damage":               55,
                "damage_type":  	"����",
		"dodge_msg":
"$N�ƺ���Ҫ������$n����$n������Ť���£������Ʊ��˹�ȥ��\n"
"$N��Ȼ����һ�������ȴ����������"+HIW"����ʬ�𼣡�"NOR"�İ��\n",
		"dodge_power":		10,
		"parry_msg":
"$n��׼���ƣ���$Wӭȥ��ֻ�����ۡ���һ�����룬$n����Ӱ�Ѳ����ˡ�\n",
		"parry_power":		10,
        ]), 
        ([      "name":                 "�����ʬ",
                "action":
"ֻ��$N�����Ṧ������һ�����ε�ǽ�ڣ���$n�����ƽ���\n"
"��ת��$N��Ȼһ������$n��$l����һ��"+HIW"�������ʬ��"NOR"",
                "dodge":                -10,
                "parry":                -30,
                "damage":               45,
                "damage_type":  	"����",
		"dodge_msg":
"$n��֨֨�����������˫��һ�㣬��$Nͷ�����˹�ȥ��\n",
		"dodge_power":		10,
		"parry_msg":
"$nԭ�ز��������������ݰ㼲ת��$N��Ȼ���У�ȴ��$nжȥ������\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "��ʬ����",
                "action":
"$N�Ż��󿪣�����ɥʧ����־һ�㣬�����������е�$w��$n��ȥ��\n"
"����"+HIW"����ʬ���⡹"NOR"��Ȼ���գ���������󣬱Ƶ�$n��������",
                "dodge":                -50,
                "parry":                -50,
                "damage":               70,
                "damage_type":  	"����",
		"dodge_msg":
"$næ��һ��"+HIW"����ʬ���⡹"NOR"��ϥ�ǲ��䣬Ӳ�����������£���Ȼ�ܹ���$N��������\n",
		"dodge_power":		10,
		"parry_msg":
"$n�ۼ���������Ȼ���ܲ��ã�������ӭ��ֻ�����ۡ���һ����\n"
"$N�Ľ������а��񣬾�Ȼ��$n����Ӱ�졣\n",
		"parry_power":		10,
        ]),
});


int valid_learn(object me)
{
        object ob;

	if(me->query("family/family_name") != "�ݿ�ɽ�޵׶�")
		return notify_fail("�㲻ϰ��Ѫ�ȣ�ѧ���˿ݹǵ���\n");
        if( (int)me->query("max_force") < 350 )
                return notify_fail("�����������������ѧ�ݹǵ���������Щ���������ɡ�\n");

	if ((int)me->query_skill("kugu-blade")>=me->query("wudidong/sell_reward"))
	    return notify_fail("��Ŀݹǵ��Ѿ����˼��ޣ���Ҫ�����Ѫ����������Ϊ��\n");
        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������������\n");
        return 1;
}

int practice_skill(object me)
{
    if (me->query_skill("kugu-blade", 1) < 180)
        return notify_fail("�����Ϊ�����������ݹǵ���\n");
    if ( me->query("family/master_id") != "yu shu" )
	return notify_fail("ʦ����û�н��������ϰ�ݹǵ��ķ��š�\n");
    if (me->query("kee") < 50)
	return notify_fail("����������㣬�޷����ݹǵ���\n");
    if (me->query("force") < 50)
	return notify_fail("�������̫�ͣ��޷�����Ծ��ͬʱ�赶��\n");
    me->add("kee", -5);
    me->add("force", -5);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="dodge"||usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}
string query_dodge_msg(string limb)
{
	return action[random(sizeof(action))]["dodge_msg"];
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if ((int)me->query_skill("kugu-blade", 1) % 10 == 0 ) {
		tell_object(me, "\n��ͻȻ��������ȱ�˵�ʲô������\n\n");
		me->add_maximum_force(-2);
	}
}

string perform_action_file(string func)
{
	return CLASS_D("yaomo") + "/wudidong/kugu-blade/"+func;
}