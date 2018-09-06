/**
 * @file
 *
 * \brief To store different models of DNA evolution.
 *
 * Declares an interface for defintion of different point mutation models.
 */
#ifndef POINT_MUTATION_MODELS_H
#define POINT_MUTATION_MODELS_H

#include <cmath>

#include "constants.h"

namespace rcombinator
{
    /// To represent a model of DNA evolution through point mutations
    class PointMutationModel
    {
    protected:
        /// The transition rate matrix (unscaled)
        NucMatrix Q_mat;
        /// The transition matrix for timestep \a t_stored
        NucMatrix T_mat;
        /// T_mat = exp(scale * Q_mat * time)
        double scale;
        /// The timestep jump for which our transition matrix is valid
        double t_stored;

    public:
        /// Constructor that allocates memory for transition matrix
        PointMutationModel(double scale = 1);

        /** Use the default destructor.
         *  Is virtual because we want all specific point mutation models to
         *  derive from this class.
         */
        virtual ~PointMutationModel() = default;

        /** Returns a rate matrix for the mutations.
         *  After \a t years have passed, the probability is exp(rate*t).
         */
        ReturnsNucMatrix get_Q;

        /** Returns a transition matrix to represent the probabilities of
         *  mutations from each nucleotide to the other.
         *  \a t is the time that has passed in millions of years.
         *  P(A to B) is matrix(A, B).
         *
         * P(t) = exp(scale*Qt)
         */
        virtual ReturnsNucMatrixFromDouble get_transition_matrix = 0;
    };

    /// General Time Reversible Model, Tavare 1986
    class GTRModel : public PointMutationModel
    {
    public:
        /** 4 equilibrium base frequency parameters, 6 substitution rate
         * parameters and 1 scale parameter.
         * pi_X  = equilibrium base frequencies
         * X2Y   = rate of X becoming Y
         * scale = the scalar by which the matrix is to be scaled to get
         *         mutations/million years
         */
        GTRModel(double pi_T=0.25, double pi_C=0.25,
                 double pi_A=0.25, double pi_G=0.25,
                 double T2C=1, double T2A=1, double T2G=1,
                 double C2A=1, double C2G=1,
                 double A2G=1,
                 double scale=1);

        /// To be computed using exponentiation of Q
        ReturnsNucMatrixFromDouble get_transition_matrix override;
    };

    /// Tamura ane Nei 1983 Model
    class T93Model : public GTRModel
    {
    public:
        /** 4 equilibrium base frequency parameters, 2 substitution rate
         * parameters and 1 scale parameter.
         * pi_X  = same as for GTR
         * k1    = rate of transition
         * k2    = rate of transversion
         * scale = same as for GTR
         */
        T93Model(double pi_T=0.25, double pi_C=0.25,
                 double pi_A=0.25, double pi_G=0.25,
                 double k1=1, double k2=1,
                 double scale=1);

        /// To be computed using exponentiation of Q
        ReturnsNucMatrixFromDouble get_transition_matrix override;


    };

    /// Hasegawa, Kishino and Yano 1985 Model
    class HKY85Model : public T93Model
    {
    public:
        /** 4 equilibrium base frequency parameters, 1 substitution rate
         * parameter and 1 scale parameter.
         * pi_X  = same as for GTR
         * k     = rate of transitions/transversions (assuming other rate is 1)
         * scale = same as for GTR
         */
        HKY85Model(double pi_T=0.25, double pi_C=0.25,
                   double pi_A=0.25, double pi_G=0.25,
                   double k=1, double scale=1);

        /// To be computed using exponentiation of Q
        ReturnsNucMatrixFromDouble get_transition_matrix override;
    };

    /// Felsenstein 1981 Model
    class F81Model : public HKY85Model
    {
    public:
        /** 4 equilibrium base frequency parameters and 1 scale parameter.
         * pi_X  = same as for GTR
         * scale = same as for GTR
         */
        F81Model(double pi_T=0.25, double pi_C=0.25,
                 double pi_A=0.25, double pi_G=0.25,
                 double scale=1);

        /// To be computed using exponentiation of Q
        ReturnsNucMatrixFromDouble get_transition_matrix override;
    };

    /// Kimura 2 Parameter Model, 1980
    class K80Model : public HKY85Model
    {
    public:
        /** 1 substitution rate parameter and 1 scale parameter.
         * k     = rate of transitions/transversions (assuming other rate is 1)
         * scale = same as for GTR
         */
        K80Model(double k=Consts::K80_K, double scale=Consts::K80_SCALE);

        /// Computed by exploiting symmetry
        ReturnsNucMatrixFromDouble get_transition_matrix override;
    };

    /// Jules and Cantor, 1969
    class JC69Model : public K80Model
    {
    public:
        /** 1 scale parameter.
         * scale = same as for GTR
         */
        JC69Model(double scale=Consts::JC69_SCALE);
    };
}

#endif //POINT_MUTATION_MODELS_H
