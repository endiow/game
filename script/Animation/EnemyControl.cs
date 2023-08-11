using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyControl : MonoBehaviour
{
    public Enemy enemy;
    public Animator animator;
    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        switch (enemy.EnemyLogic.enemyState)
        {
            case EnemyState.Idle:
                animator.SetInteger("EnemyState", 0);
                break;

            case EnemyState.Move:
                animator.SetInteger("EnemyState", 1);
                break;

            case EnemyState.Hunt:
                animator.SetInteger("EnemyState", 2);
                break;

            case EnemyState.Attack:
                animator.SetInteger("EnemyState", 3);
                break;

            case EnemyState.Death:
                animator.SetInteger("EnemyState", 4);
                break;
        }
    }
}

