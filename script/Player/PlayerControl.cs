using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Animations;

public class PlayerControl : MonoBehaviour
{
    //public Animation animation;
    //Animation animations;
    #region MouseControl
    [Header("物体")]
    public Transform Player_Object;
    public Transform Player_Camera;

    [Header("上下角度限制")]
    public float Rotation_min = -80;
    public float Rotation_max = 80;

    [Header("玩家视角旋转速度")]
    [Range(1f, 500f)]
    public float MouseControl_Speed = 100f;

    private float PlayerRotation_Y = 0f;
	#endregion

	[Space]
    #region PlayerMove
    public CharacterController controller;
    public LayerMask isGround_layer;
    public Transform isGround_Transform;

    [Header("玩家移动速度")]
    public float PlayerMoveSpeed;
    public float PlayerMoveSpeed_Normal;
    public float PlayerMoveSpeed_High;
	#endregion

	[Space]
	#region PlayerGravity
	[Header("重力大小")]
    public float gravity = -0.1f;

	[Header("跳跃高度")]
    public float jump_height = 3f;

    [SerializeField]
    private Vector3 gravity_vector3;

	[Header("地面检测")]
    [SerializeField]
    private bool isGround;
    public float isGround_radius = 0.3f;
	#endregion

	private void Start()
    {
        Cursor.visible = false;

        if (controller == null)  
        {
            this.gameObject .AddComponent<CharacterController>();  
        }
    }

	private void Update()
	{
        PlayerMouseControl();
        PlayerMove();
        PlayerGravity();

        //if (Input.GetMouseButtonDown(0)) 
        //{
        //    animation.Play();
        //}
    }

    /// <summary>
    /// 鼠标控制视角移动
    /// </summary>
	void PlayerMouseControl()
    {
        float xMouse = Input.GetAxis("Mouse X") * MouseControl_Speed * Time.deltaTime;
        float YMouse = Input.GetAxis("Mouse Y") * MouseControl_Speed * Time.deltaTime;

        PlayerRotation_Y -= YMouse;
        PlayerRotation_Y = Mathf.Clamp(PlayerRotation_Y, Rotation_min, Rotation_max);
        Player_Object.Rotate(Vector3.up * xMouse);

        Quaternion quaternion = Quaternion.Euler(PlayerRotation_Y, 0, 0);

        Player_Camera.localRotation = quaternion;
    }

    /// <summary>
    /// WASD控制人物移动
    /// </summary>
    void PlayerMove()
    {
        float move_x = Input.GetAxis("Horizontal");
        float move_y = Input.GetAxis("Vertical");
        Vector3 move_direct = transform.right * move_x + transform.forward * move_y;

        if (!Input.GetKey("left shift"))
        {
            PlayerMoveSpeed = PlayerMoveSpeed_Normal;
        }
        if (Input.GetKey("left shift"))
        {
            PlayerMoveSpeed = PlayerMoveSpeed_High;
        }

        controller.Move(move_direct * PlayerMoveSpeed * Time.deltaTime);

    }

    /// <summary>
    /// Space进行跳跃，并模拟重力效果
    /// </summary>
    void PlayerGravity()
    {
        gravity_vector3.y += gravity * Time.deltaTime;

        isGround = Physics.CheckSphere(isGround_Transform.position, isGround_radius, isGround_layer);

        controller.Move(gravity_vector3);

        if (isGround == true && gravity_vector3.y < 0)
        {
            gravity_vector3.y = -0.05f;
        }

        if (Input.GetButtonDown("Jump") && isGround)
        {
            gravity_vector3.y = jump_height;
        }
    }
}
