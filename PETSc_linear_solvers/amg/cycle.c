/*BHEADER**********************************************************************
 * (c) 1996   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision$
 *********************************************************************EHEADER*/

/******************************************************************************
 *
 * AMG cycling routine
 *
 *****************************************************************************/

#include "headers.h"


/*--------------------------------------------------------------------------
 * hypre_AMGCycle
 *--------------------------------------------------------------------------*/

int         hypre_AMGCycle(hypre_AMGData *amg_data, 
                           hypre_Vector  **U_array,
                           hypre_Vector  **F_array)

{

/* Data Structure variables */

   hypre_CSRMatrix    **A_array;
   hypre_CSRMatrix    **P_array;
   hypre_Vector    *Vtemp;

   int     **CF_marker_array;
   int     **unknown_map_array;
   int     **point_map_array;
   int     **v_at_point_array;

   int       cycle_op_count;   
   int       cycle_type;
   int       num_levels;
   int       num_unknowns;

   int      *num_coeffs;
   int      *num_grid_sweeps;   
   int      *grid_relax_type;   
/*   int     **grid_relax_points;  */
   int      *grid_relax_points[4];


/* Local variables  */

   int      *lev_counter;
   int       Solve_err_flag;
   int       k;
   int       j;
   int       level;
   int       cycle_param;
   int       coarse_grid;
   int       fine_grid;
   int       Not_Finished;
   int       num_sweep;
   int       relax_type;
   int       relax_points;

   double    alpha;
   double    beta;
/*   double   *D_mat;
   double   *S_vec;  */
   
/* Acquire data and allocate storage */

   A_array           = hypre_AMGDataAArray(amg_data);
   P_array           = hypre_AMGDataPArray(amg_data);
   CF_marker_array   = hypre_AMGDataCFMarkerArray(amg_data);
   unknown_map_array = hypre_AMGDataUnknownMapArray(amg_data);
   point_map_array   = hypre_AMGDataPointMapArray(amg_data);
   v_at_point_array  = hypre_AMGDataVatPointArray(amg_data);
   Vtemp             = hypre_AMGDataVtemp(amg_data);
   num_levels        = hypre_AMGDataNumLevels(amg_data);
   cycle_type        = hypre_AMGDataCycleType(amg_data);
   num_unknowns      =  hypre_CSRMatrixNumRows(A_array[0]);

   num_grid_sweeps     = hypre_AMGDataNumGridSweeps(amg_data);
   grid_relax_type     = hypre_AMGDataGridRelaxType(amg_data);
/*   grid_relax_points   =  hypre_AMGDataGridRelaxPoints(amg_data); */

/* temporary fix */
   for (j = 0; j < 3; j++)
   {
      grid_relax_points[j] = hypre_CTAlloc(int,2);
      grid_relax_points[j][0] = 1;
      grid_relax_points[j][1] = -1;
   }
   grid_relax_points[3] = hypre_CTAlloc(int,1);
   grid_relax_points[3][0] = 9;    
/*end temporary fix */

   cycle_op_count = hypre_AMGDataCycleOpCount(amg_data);


    lev_counter = hypre_CTAlloc(int, num_levels);

/*   D_mat = hypre_CTAlloc(double, num_unknowns * num_unknowns);
   S_vec = hypre_CTAlloc(double, num_unknowns); */

/* Initialize */

   Solve_err_flag = 0;

   num_coeffs = hypre_CTAlloc(int, num_levels);
   num_coeffs[0]    = hypre_CSRMatrixNumNonzeros(A_array[0]);

   for (j = 1; j < num_levels; j++)
       num_coeffs[j] = hypre_CSRMatrixNumNonzeros(A_array[j]);


/*------------------------------------------------------------------------
 *    Initialize cycling control counter
 *
 *     Cycling is controlled using a level counter: lev_counter[k]
 *     
 *     Each time relaxation is performed on level k, the
 *     counter is decremented by 1. If the counter is then
 *     negative, we go to the next finer level. If non-
 *     negative, we go to the next coarser level. The
 *     following actions control cycling:
 *     
 *     a. lev_counter[0] is initialized to 1.
 *     b. lev_counter[k] is initialized to cycle_type for k>0.
 *     
 *     c. During cycling, when going down to level k,
 *        lev_counter[k] is set to the max of (lev_counter[k],cycle_type)
*------------------------------------------------------------------------*/

   Not_Finished = 1;

   lev_counter[0] = 1;
   for (k = 1; k < num_levels; ++k) 
   {
       lev_counter[k] = cycle_type;
   }

/*------------------------------------------------------------------------
 * Set the initial cycling parameters
 *
 *     1. ntrlx[0] can have several meanings (nr1,nr2)
 *     nr1 defines the first fine grid sweep
 *     nr2 defines any subsequent sweeps
 *     
 *     ntrlx[0] = 0   - (0,0)
 *     ntrlx[0] = 1   - (ntrlx[1],ntrlx[2])
 *     ntrlx[0] > 9   - standard meaning
 *-----------------------------------------------------------------------*/
   
   level = 0;
   cycle_param = 0;

/*------------------------------------------------------------------------
 * Main loop of cycling
 *-----------------------------------------------------------------------*/
  
   while (Not_Finished)
   {
   
      num_sweep = num_grid_sweeps[cycle_param];
      relax_type = grid_relax_type[cycle_param];

/*------------------------------------------------------------------------
 * Do the relaxation num_sweep times
 *-----------------------------------------------------------------------*/

      for (j = 0; j < num_sweep; j++)
      {
         relax_points =   grid_relax_points[cycle_param][j];

         /*-----------------------------------------------
          * VERY sloppy approximation to cycle complexity
          *-----------------------------------------------*/

         if (level < num_levels -1)
         {
            switch (relax_points)
            {
                 case 1:
                    cycle_op_count += num_coeffs[level+1]; 
  
                 case -1: 
                    cycle_op_count += (num_coeffs[level]-num_coeffs[level+1]); 
            }
         }
	 else
         {
            cycle_op_count += num_coeffs[level]; 
         }

         Solve_err_flag = hypre_AMGRelax(A_array[level], 
                                         F_array[level],
                                         CF_marker_array[level],
                                         relax_type,
                                         relax_points,
                                         U_array[level],
                                         Vtemp);

         if (Solve_err_flag != 0) return(Solve_err_flag);

            
      }


/*------------------------------------------------------------------------
 * Decrement the control counter and determine which grid to visit next
 *-----------------------------------------------------------------------*/

      --lev_counter[level];
       
      if (lev_counter[level] >= 0 && level != num_levels-1)
      {
                               
/*------------------------------------------------------------------------
 * Visit coarser level next.  Compute residual using hypre_Matvec.
 * Perform restriction using hypre_MatvecT.
 * Reset counters and cycling parameters for coarse level
 *-----------------------------------------------------------------------*/

          fine_grid = level;
          coarse_grid = level + 1;

          hypre_SetVectorConstantValues(U_array[coarse_grid], 0.0);
          
          hypre_CopyVector(F_array[fine_grid],Vtemp);
          alpha = -1.0;
          beta = 1.0;
          hypre_Matvec(alpha, A_array[fine_grid], U_array[fine_grid],
                 beta, Vtemp);

          alpha = 1.0;
          beta = 0.0;
          hypre_MatvecT(alpha,P_array[fine_grid],Vtemp,
                  beta,F_array[coarse_grid]);

          ++level;
          lev_counter[level] = max(lev_counter[level],cycle_type);
          cycle_param = 1;
          if (level == num_levels-1) cycle_param = 3;
      }

      else if (level != 0)
      {
                            
/*------------------------------------------------------------------------
 * Visit finer level next.  Interpolate and add correction using hypre_Matvec.
 * Reset counters and cycling parameters for finer level.
 *-----------------------------------------------------------------------*/

          fine_grid = level - 1;
          coarse_grid = level;
          alpha = 1.0;
          beta = 1.0;

          hypre_Matvec(alpha, P_array[fine_grid], U_array[coarse_grid],
                 beta, U_array[fine_grid]);            

          --level;
          cycle_param = 2;
          if (level == 0) cycle_param = 0;
      }
      else
      {
             Not_Finished = 0;
      }
   }

   hypre_AMGDataCycleOpCount(amg_data) = cycle_op_count;

   hypre_TFree(lev_counter);

/*   hypre_TFree(D_mat);
   hypre_TFree(S_vec);  */

   return(Solve_err_flag);
}
