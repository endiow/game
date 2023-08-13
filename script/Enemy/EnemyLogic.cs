using System;
//using System.Collections;
//using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.Audio;

public enum EnemyState
    {
        Idle,
        Move,
        Hunt,
        Attack,
        Death
    }

[System.Serializable]
public class EnemyLogic 
{
    public EnemyState enemyState;
    public NavMeshAgent navMeshAgent;
    public GameObject EnemyObj;
    public GameObject PlayerObj;
    public EnemyInfo EnemyInfo;

    public AudioSource AudioSourceW;
    public AudioSource AudioSourceH;
    public AudioSource AudioSourceA;

    public Transform[] EnemyMoveTargetPositions;

    public float DeathTime = 2f;
    public float AttackBuffer;
    public Vector3 TargetMovePos;
    public float IdleTime;
    public  bool IsMove = false;
   
    public void EnemyStateControl()//状态机的控制
    {
        switch(enemyState)
        {
            case EnemyState.Idle:
                EnemyIdle();
                break;

            case EnemyState.Move:
                EnemyMove();
                break;

            case EnemyState.Hunt:
                EnemyHunt();
                break;

            case EnemyState.Attack:
                EnemyAttack();
                break;

            case EnemyState.Death:
                EnemyDeath();
                break;
        }
    }

    public void EnemyIdle()
    {
        AudioSourceW.Stop();
        AudioSourceH.Stop();

        IdleTime -= Time.deltaTime;
        if (IdleTime <= 0f)
        {
            enemyState = EnemyState.Move;
            IsMove = false;
        }
    }

    public void EnemyMove()//站立后随机向八个方位中的一个移动
    {
        AudioSourceW.Play();
        AudioSourceH.Stop();

        if (IsMove == false)
        {
            int PosIndex = UnityEngine.Random.Range(0, 8);
            TargetMovePos = EnemyMoveTargetPositions[PosIndex].position;
            IsMove = true;
        }

        if (IsMove == true)
        {
            navMeshAgent.SetDestination(TargetMovePos);
            if (Vector3.Distance(EnemyObj.transform.position, TargetMovePos) <= 2f)
            {
                IsMove = false;
                enemyState = EnemyState.Idle;
                IdleTime = UnityEngine.Random.Range(0f, 15f);
            }
        }
    }

    public void EnemyHunt()
    {
        AudioSourceH.Play();
        AudioSourceW.Stop();

        navMeshAgent.SetDestination(PlayerObj.transform.position);
        //if (Vector3.Distance(EnemyObj.transform.position, PlayerObj.transform.position) <= 2f)
        //{
        //    enemyState = EnemyState.Attack;
        //    IdleTime = Random.Range(0f, 15f);
        //}
    }

    public void EnemyAttack()//每隔attackspeed攻击玩家
    {
        AudioSourceW.Stop();
        AudioSourceH.Stop();

        navMeshAgent.SetDestination(PlayerObj.transform.position);
        AttackBuffer -= Time.deltaTime;
        if (AttackBuffer <= 0f)
        {
            AudioSourceA.Play();
            PlayerObj.transform.parent.gameObject.GetComponent<Player>().PlayerHp -= EnemyInfo.EnemyAttackNumber;
            AttackBuffer = EnemyInfo.EnemyAttackSpeed;
        }        
    }
    
    public void EnemyDeath()
    {
        AudioSourceW.Stop();
        AudioSourceH.Stop();

        DeathTime -= Time.deltaTime;
        if (DeathTime <= 0f)
        {
            GameObject.Destroy(EnemyObj);
        }        
    }

}
